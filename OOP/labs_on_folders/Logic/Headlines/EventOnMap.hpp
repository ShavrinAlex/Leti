#pragma once
#include "Event.hpp"
#include "Map.hpp"

class EventOnMap: public Event{
    protected:
        Map* map;
    public:
        //initialization
        EventOnMap(Map* map);

        //destruction
        ~EventOnMap();
};
