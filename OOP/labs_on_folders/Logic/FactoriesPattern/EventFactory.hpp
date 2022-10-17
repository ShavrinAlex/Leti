#pragma once
#include "../Events/Event.hpp"

class EventFactory{
    public:
        virtual Event* createEvent1() = 0;
        virtual Event* createEvent2() = 0;
        virtual Event* createEvent3() = 0;
        virtual ~EventFactory(){};
};
