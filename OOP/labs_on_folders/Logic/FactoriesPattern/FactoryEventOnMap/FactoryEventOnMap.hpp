#pragma once
#include "../EventFactory.hpp"
#include "../../Map/Map.hpp"
class EventGenerator;

class FactoryEventOnMap: public EventFactory{
    private:
        Map* map;
        EventFactory* factory_event_on_game;
        EventGenerator* event_generator;
    public:
        //initialization
        FactoryEventOnMap(Map* map, EventFactory* factory_event_on_game, EventGenerator* event_generator);

        //create event
        Event* createEvent1() override;
        Event* createEvent2() override;
        Event* createEvent3() override;

        //destruction
        ~FactoryEventOnMap();
};
