#include "timer.hpp"
#include <chrono>


typedef std::chrono::high_resolution_clock myClock;


Timer::Timer() {
    this->isRunning = false;
};


void Timer::start() {
    this->startTime = myClock::now();
    this->isRunning = true;
};


void Timer::stop() {
    this->stopTime = myClock::now();
    this->isRunning = false;
};


double Timer::elapsed() const {
    std::chrono::time_point<myClock> endTime;
    
    if (isRunning) {
        endTime = myClock::now();
    } else {
        endTime = this->stopTime;
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - this->startTime).count();
};
