#include "EventOnMap.hpp"

class SetWallEvent: public EventOnMap{
    public:
        //initialization
        SetWallEvent(Map* map);

        //execute
        EventStatus execute() override;
};
