#pragma once
#include "../../Event.hpp"
#include "../../../Map/Map.hpp"
#include "../../../Generators/Generator/Generator.hpp"
#include "../../../Logging/Log/Log.hpp"
#include "../../../MediatorPattern/GameElement/GameElementDescription.hpp"

class EventOnMap: public Event, public GameElement<Log*>{
    protected:
        Map* map;
        Generator* generator;
    public:
        //initialization
        EventOnMap(Map* map, Generator* generator);

        //destruction
        ~EventOnMap();
};
