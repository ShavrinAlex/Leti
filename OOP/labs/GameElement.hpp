#pragma once
#include "Mediator.hpp"

class GameElement{
    protected:
        Mediator* mediator;
    public:
        void setMediator(Mediator* mediator);    
};
