#include "../Headlines/Observable.hpp"

//initialization
Observable::Observable(){
    this->observer = nullptr;
};

//set observer
void Observable::setObserver(Observer* observer){
    this->observer = observer;
};

//notify observer
void Observable::notify(){
    this->observer->update();
};
