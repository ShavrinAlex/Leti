#pragma once
#include "../Mediator.hpp"

template <typename T>
class GameElement{
    protected:
        Mediator<T>* mediator;
    public:
        //set mediator
        void setMediator(Mediator<T>* mediator);    

        //destruction
        ~GameElement();
};

#include "GameElementDefenition.hpp"
