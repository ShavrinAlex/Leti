#pragma once
#include "Event.hpp"

class ConditionalEvent: public Event{
    protected:
        virtual bool checkConditional() = 0;
    public:
        virtual ~ConditionalEvent(){};
};
