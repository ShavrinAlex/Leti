#pragma once
#include "Enumerations.hpp"

class Event{
    public:
        EventStatus virtual execute() = 0;
        virtual ~Event(){};
};
