#pragma once
#include "../EventOnMap/EventOnMap.hpp"

class SetWallEvent: public EventOnMap{
    public:
        //initialization
        SetWallEvent(Map* map);

        //execute
        EventStatus execute() override;
};
