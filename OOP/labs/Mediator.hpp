class GameElement;
#pragma once
#include <string>


class Mediator{
    public:
        virtual void send(std::string message, GameElement* element) = 0;
        virtual ~Mediator(){};
};
