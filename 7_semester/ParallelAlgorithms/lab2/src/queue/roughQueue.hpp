#include <queue>
#include <mutex>
#include <condition_variable>


template <typename T>
class RoughQueue {
private:
    mutable std::mutex mutex;
    size_t maxSize;                         
    std::queue<T> queue;
    std::condition_variable popCondition;
    std::condition_variable pushCondition;
public:
    explicit RoughQueue(size_t maxSize);

    void push(T value);
    void pop(T& value);
};


template <typename T>
RoughQueue<T>::RoughQueue(size_t maxSize) {
    this->maxSize = maxSize;
};


template <typename T>
void RoughQueue<T>::push(T value) {
    std::unique_lock<std::mutex> lock(this->mutex);

    this->pushCondition.wait(lock, [this] {
        return this->queue.size() < this->maxSize;
    });

    this->queue.push(value);
    this->popCondition.notify_one();
};


template <typename T>
void RoughQueue<T>::pop(T& value) {
    std::unique_lock<std::mutex> lock(this->mutex);

    this->popCondition.wait(lock, [this] {
        return !this->queue.empty();
    });

    value = this->queue.front();
    this->queue.pop();
    this->pushCondition.notify_one();
};