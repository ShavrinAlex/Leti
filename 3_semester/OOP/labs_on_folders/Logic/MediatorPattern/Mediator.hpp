#pragma once
#include <iostream>

template <typename T>
class Mediator{
    public:
        virtual void send(T message) = 0;
        virtual ~Mediator(){};
};
