#pragma once
class GameElement;
#include "../Utility/Enumerations.hpp"

class Mediator{
    public:
        virtual void send(KeyboardCommand message, GameElement* element) = 0;
        virtual ~Mediator(){};
};
