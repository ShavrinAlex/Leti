#pragma once
#include <memory>
#include <atomic>
#include <iostream>
#include <unordered_set>


template <typename T>
class LockFreeQueue {
private:
    struct Node {
        T data;
        std::atomic<Node*> next;
        Node() {
            this->next = nullptr;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        };
    };

    struct ThreadInfo {
        std::atomic<Node*> hp1;
        std::atomic<Node*> hp2;
        std::vector<Node*> toBeDeletedList;
        int toBeDeletedCount;
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;
    std::vector<ThreadInfo> threadsInfo;

    void retire(const int threadNum, Node* nodeToDelete);
    void scan(const int threadNum);
    void deleteRecursive(Node* node);
public:
    LockFreeQueue(const int threadCount);
    ~LockFreeQueue();
    void push(T value, const int threadNum);
    bool pop(T& value, const int threadNum);
};


template <typename T>
LockFreeQueue<T>::LockFreeQueue(const int threadCount) : threadsInfo(threadCount) {
    this->head.store(new Node());
    this->tail.store(this->head.load());

    for (auto& info : this->threadsInfo) {
        info.hp1.store(nullptr);
        info.hp2.store(nullptr);
        info.toBeDeletedList.resize(4 * threadCount);
        info.toBeDeletedCount = 0;
    }
};


template <typename T>
LockFreeQueue<T>::~LockFreeQueue() {
    for (const auto& info : this->threadsInfo) {
        for (Node* node : info.toBeDeletedList) {
            delete node;
        }
    }
    this->deleteRecursive(this->head);
};


template <typename T>
void LockFreeQueue<T>::push(T value, const int threadNum) {
    Node* newTail = new Node(value);
    while (true) {
        Node* oldTail = this->tail.load();
        Node* tailNext = nullptr;
        this->threadsInfo[threadNum].hp1.store(oldTail);

        if (oldTail->next.compare_exchange_strong(tailNext, newTail)) {
            this->tail.compare_exchange_strong(oldTail, newTail);
            break;
        } else {
            this->tail.compare_exchange_strong(oldTail, oldTail->next.load());
        }
    }
    this->threadsInfo[threadNum].hp1.store(nullptr);
};


template <typename T>
bool LockFreeQueue<T>::pop(T& value, const int threadNum) {
    while (true) {
        Node* oldHead = this->head.load();
        this->threadsInfo[threadNum].hp1.store(oldHead);
        
        Node* oldTail = this->tail.load();
        Node* newHead = oldHead->next.load();
        this->threadsInfo[threadNum].hp2.store(newHead);

        if (oldHead == oldTail) {
            if (newHead == nullptr) {
                this->threadsInfo[threadNum].hp1.store(nullptr);
                this->threadsInfo[threadNum].hp2.store(nullptr);
                continue;
            }
            this->tail.compare_exchange_strong(oldTail, newHead);
        } else {
            value = newHead->data;
            if (this->head.compare_exchange_strong(oldHead, newHead)) {
                this->threadsInfo[threadNum].hp1.store(nullptr);
                this->threadsInfo[threadNum].hp2.store(nullptr);
                this->retire(threadNum, oldHead);   
                return true;
            }
        }
    }   
};


template <typename T>
void LockFreeQueue<T>::retire(const int threadNum, LockFreeQueue<T>::Node* nodeToDelete) {
    ThreadInfo& curThreadInfo = this->threadsInfo[threadNum];
    curThreadInfo.toBeDeletedList[curThreadInfo.toBeDeletedCount++] = nodeToDelete;

    if (curThreadInfo.toBeDeletedCount == curThreadInfo.toBeDeletedList.size()) {
        scan(threadNum);
    }
};


template <typename T>
void LockFreeQueue<T>::scan(const int threadNum) {
    std::unordered_set<Node*> hps;

    for (const auto& info : this->threadsInfo) {
        hps.insert(info.hp1);
        hps.insert(info.hp2);
    }

    int newToBeDeletedCount = 0;
    auto& toBeDeletedList = this->threadsInfo[threadNum].toBeDeletedList;

    for (int i = 0; i < toBeDeletedList.size(); i++) {
        if (hps.count(toBeDeletedList[i])) {
            Node* node = toBeDeletedList[i];
            toBeDeletedList[i] = nullptr;
            toBeDeletedList[newToBeDeletedCount++] = node;
        } else {
            delete toBeDeletedList[i];
            toBeDeletedList[i] = nullptr;
        }
    }
    this->threadsInfo[threadNum].toBeDeletedCount = newToBeDeletedCount;
};


template <typename T>
void LockFreeQueue<T>::deleteRecursive(LockFreeQueue<T>::Node* node) {
    if (node != nullptr) {
        this->deleteRecursive(node->next);
        delete node;
    }
};

