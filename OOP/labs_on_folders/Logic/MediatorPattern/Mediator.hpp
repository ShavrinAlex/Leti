#pragma once
class GameElement;
#include <iostream>

class Mediator{
    public:
        virtual void send(std::string message, GameElement* element) = 0;
        virtual ~Mediator(){};
};
