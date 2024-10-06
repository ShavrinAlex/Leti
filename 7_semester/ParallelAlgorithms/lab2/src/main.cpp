#include "queue/roughQueue.hpp"
#include "queue/thinQueue.hpp"
#include "producer/producer.hpp"
#include "consumer/consumer.hpp"
#include "timer/timer.hpp"
#include <functional>
#include <thread>
#include <iostream>


#define QUEUE_SIZE 7


template <typename QueueType>
void testQueue(const int producersCount, const int consumersCount, const int producerPower, const int consumerPower) {
    QueueType queue = QueueType(QUEUE_SIZE);
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;
    
    for (int i = 0; i < producersCount; i++) {
        producers.emplace_back(thProducer<QueueType>, std::ref(queue), producerPower);
    }
    for (int i = 0; i < consumersCount; i++) {
        consumers.emplace_back(thConsumer<QueueType>, std::ref(queue), consumerPower);
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
        producersCount = std::stoi(argv[1]);
        consumersCount = std::stoi(argv[2]);   
        producerPower = std::stoi(argv[3]);
        consumerPower = std::stoi(argv[4]); 
    } else {
        producersCount = consumersCount = 7;
        producerPower = consumerPower = 10;
    }

    timer.start();
    testQueue<RoughQueue<myPair>>(producersCount, consumersCount, producerPower, consumerPower);
    timer.stop();
    std::cout << "RoughQueue: " << timer.elapsed() << std::endl;

    timer.start();
    testQueue<ThinQueue<myPair>>(producersCount, consumersCount, producerPower, consumerPower);
    timer.stop();
    std::cout << "ThinQueue: " << timer.elapsed() << std::endl;

    return 0;
}
