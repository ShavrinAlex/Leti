#include <queue>
#include <mutex>
#include <condition_variable>


template <typename T>
class ThinQueue {
private:
    struct Node {
        std::shared_ptr<T> data;
        std::unique_ptr<Node> next;
    };
    std::unique_ptr<Node> head;
    Node* tail;

    mutable std::mutex headMutex;
    mutable std::mutex tailMutex;
    std::condition_variable popCondition;
    std::condition_variable pushCondition;

    size_t maxSize;
    size_t currentSize;                          
    std::queue<T> queue;

    Node* getTail() const;
    std::unique_lock<std::mutex> waitData();
    std::unique_ptr<Node> popHead();
    std::unique_ptr<Node> waitPopHead(T& value);

public:
    explicit ThinQueue(size_t maxSize);

    void push(T value);
    void pop(T& value);
};


template <typename T>
ThinQueue<T>::ThinQueue(size_t maxSize) {
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->head = std::make_unique<Node>();
    this->tail = this->head.get();
};


template <typename T>
typename ThinQueue<T>::Node* ThinQueue<T>::getTail() const {
    std::lock_guard<std::mutex> tailLock(this->tailMutex);
    return this->tail;
};


template <typename T>
std::unique_lock<std::mutex> ThinQueue<T>::waitData() {
    std::unique_lock<std::mutex> headLock(this->headMutex);
    this->popCondition.wait(headLock, [this] { 
        return this->head.get() != this->getTail(); 
    });
    return std::move(headLock);
};


template <typename T>
std::unique_ptr<typename ThinQueue<T>::Node> ThinQueue<T>::popHead() {
    std::unique_ptr<Node> oldHead = std::move(this->head);
    this->head = std::move(oldHead->next);
    this->currentSize--;
    return oldHead;
};


template <typename T>
std::unique_ptr<typename ThinQueue<T>::Node> ThinQueue<T>::waitPopHead(T& value) {
    std::unique_lock<std::mutex> headLock(this->waitData());
    value = std::move(*this->head->data);
    return this->popHead();
};


template <typename T>
void ThinQueue<T>::push(T value) {
    std::shared_ptr<T> newData(std::make_shared<T>(std::move(value)));
    std::unique_ptr<Node> p(new Node);

    std::unique_lock<std::mutex> tailLock(this->tailMutex);
    this->pushCondition.wait(tailLock, [this] { 
        return this->currentSize < this->maxSize; 
    });

    this->tail->data = newData;
    Node* const newTail = p.get();
    this->tail->next = std::move(p);
    this->tail = newTail;
    this->currentSize++;
    // tailLock.unlock();
    this->popCondition.notify_one();
};


template <typename T>
void ThinQueue<T>::pop(T& value) {
    std::unique_ptr<Node> oldHead = this->waitPopHead(value);
    if (oldHead) {
        this->pushCondition.notify_one();
    }
};
