#pragma once
#include "../../Event.hpp"
#include "../../../Map/Map.hpp"
#include "../../../Generators/Generator/Generator.hpp"

class EventOnMap: public Event{
    protected:
        Map* map;
        Generator* generator;
    public:
        //initialization
        EventOnMap(Map* map, Generator* generator);

        //destruction
        ~EventOnMap();
};
