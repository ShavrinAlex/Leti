#pragma once
#include "Observer.hpp"

class Observable{
    protected:
        Observer* observer;
    public:
        //initialization
        Observable();

        //set observer
        void setObserver(Observer* observer);

        //notify observer
        void notify();
};
