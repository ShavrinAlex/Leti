#pragma once
#include "../Observer.hpp"
#include <vector>

typedef std::vector < Observer* > Observers;

class Observable{
    protected:
        Observers observers;
    public:
        //initialization
        Observable();

        //add observer
        void addObserver(Observer* observer);

        //notify observers
        void notify();

        //destruction
        ~Observable();
};
