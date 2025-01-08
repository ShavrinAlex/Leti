#include "queue/roughQueue.hpp"
#include "queue/thinQueue.hpp"
#include "queue/lockFreeQueue.hpp"
#include "producer/producer.hpp"
#include "consumer/consumer.hpp"
#include "timer/timer.hpp"
#include <functional>
#include <thread>
#include <iostream>
#include <type_traits>


template <typename QueueType>
void testQueue(const int producersCount, const int consumersCount, const int producerPower, const int consumerPower) {
    QueueType* queue = nullptr;
    const int threadsAmount = producersCount + consumersCount;
    if constexpr (std::is_same<QueueType, LockFreeQueue<myPair>>::value) {
        queue = new QueueType(threadsAmount);
    } else {
        queue = new QueueType();
    }

    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;
    
    for (int i = 0; i < producersCount; i++) {
        producers.emplace_back(thProducer<QueueType>, std::ref(*queue), producerPower, i);
    }
    for (int j = producersCount; j < threadsAmount; j++) {
        consumers.emplace_back(thConsumer<QueueType>, std::ref(*queue), consumerPower, j);
    }

    for (auto& producer : producers) {
        producer.join();
    }
    for (auto& consumer : consumers) {
        consumer.join();
    }
}


int main(int argc, char* argv[]) {
    Timer timer = Timer();
    int producersCount, consumersCount, producerPower, consumerPower;
     
    if (argc == 5) {
        producerPower = std::stoi(argv[1]);
        consumerPower = std::stoi(argv[2]); 
        producersCount = std::stoi(argv[3]);
        consumersCount = std::stoi(argv[4]);   
    } else {
        producersCount = consumersCount = 6;
        producerPower = consumerPower = 10;
    }
    
    int timeRough, timeThin, timeLockFree;
    timeRough = timeThin = timeLockFree = 0;
    int countIterations = 1;
    for (int i = 0; i < countIterations; i++) {
        std::cout << "iteration " << i << std::endl;
        timer.start();
        testQueue<RoughQueue<myPair>>(producersCount, consumersCount, producerPower, consumerPower);
        timer.stop();
        timeRough += timer.elapsed();
        // std::cout << "r\n";

        timer.start();
        testQueue<ThinQueue<myPair>>(producersCount, consumersCount, producerPower, consumerPower);
        timer.stop();
        timeThin += timer.elapsed();
        // std::cout << "t\n";

        timer.start();
        testQueue<LockFreeQueue<myPair>>(producersCount, consumersCount, producerPower, consumerPower);
        timer.stop();
        timeLockFree += timer.elapsed();
        // std::cout << "l\n";
    }
    std::cout << "RoughQueue: " << timeRough/countIterations << std::endl;
    std::cout << "ThinQueue: " << timeThin/countIterations << std::endl;
    std::cout << "LockFreeQueue: " << timeLockFree/countIterations << std::endl;

    return 0;
}
