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

//notify observers
void Observable::notify(){
    for (auto observer: this->observers){
        observer->update();
    }
};

//destruction
Observable::~Observable(){
    if (observers.size()){
        for (auto observer: this->observers){
            observer = nullptr;
        }
    }
};
