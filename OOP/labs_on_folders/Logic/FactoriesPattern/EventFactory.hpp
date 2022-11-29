#pragma once
#include "../Events/Event.hpp"
#include "../Logging/Log/Log.hpp"
#include "../MediatorPattern/Mediator.hpp"

class EventFactory{
    public:
        virtual Event* createEvent1() = 0;
        virtual Event* createEvent2() = 0;
        virtual Event* createEvent3() = 0;
        virtual ~EventFactory(){};
};
