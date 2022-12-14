#pragma once
#include "../Mediator.hpp"

template <typename T>
class GameElement{
    protected:
        Mediator<T>* mediator;
    public:
        //initialization
        GameElement();

        //set mediator
        void setMediator(Mediator<T>* mediator); 

        //get mediator
        Mediator<T>* getMediator();  

        //destruction
        ~GameElement();
};

#include "GameElementDefenition.hpp"
