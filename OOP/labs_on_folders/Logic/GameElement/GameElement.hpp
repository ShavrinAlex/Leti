#pragma once
#include "../MediatorPattern/Mediator.hpp"

class GameElement{
    protected:
        Mediator* mediator;
    public:
        //set mediator
        void setMediator(Mediator* mediator);    

        //destruction
        ~GameElement();
};
