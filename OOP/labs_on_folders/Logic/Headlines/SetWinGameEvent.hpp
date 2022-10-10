#include "EventOnMap.hpp"
#include "EventFactory.hpp"
#include "EventGenerator.hpp"

class SetWinGameEvent: public EventOnMap{
    private:
        EventFactory* factory_event_on_game;
        EventGenerator* event_generator;
    public:
        //initialization
        SetWinGameEvent(Map* map, EventFactory* factory_event_on_game, EventGenerator* event_generator);

        //execute
        EventStatus execute() override;
};
