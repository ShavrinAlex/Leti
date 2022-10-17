#include "Observable.hpp"

//initialization
Observable::Observable(){
    this->observers.reserve(1);
    for (auto observer: this->observers){
        observer = nullptr;
    }
};

//set observer
void Observable::addObserver(Observer* observer){
    this->observers.emplace_back(observer);
};

//notify observer
void Observable::notify(){
    for (auto observer: this->observers){
        observer->update();
    }
};

//destruction
Observable::~Observable(){
    for (auto observer: this->observers){
        observer = nullptr;
    }
};
