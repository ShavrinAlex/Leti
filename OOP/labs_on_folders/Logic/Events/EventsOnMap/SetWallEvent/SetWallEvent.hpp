#include "../EventOnMap/EventOnMap.hpp"

class SetWallEvent: public EventOnMap{
    public:
        //initialization
        SetWallEvent(Map* map, Generator* generator);

        //execute
        EventStatus execute() override;
};
