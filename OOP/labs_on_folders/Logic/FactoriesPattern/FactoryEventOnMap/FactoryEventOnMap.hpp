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
        Event* createEvent1(Mediator<Log*>* mediator) override;
        Event* createEvent2(Mediator<Log*>* mediator) override;
        Event* createEvent3(Mediator<Log*>* mediator) override;

        //destruction
        ~FactoryEventOnMap();
};
