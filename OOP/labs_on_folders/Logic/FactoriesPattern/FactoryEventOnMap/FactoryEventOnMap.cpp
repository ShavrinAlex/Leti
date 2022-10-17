#include "FactoryEventOnMap.hpp"
#include "../../Events/EventsOnMap/SetWallEvent/SetWallEvent.hpp"
#include "../../Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.hpp"

//initialization
FactoryEventOnMap::FactoryEventOnMap(Map* map, EventFactory* factory_event_on_game, EventGenerator* event_generator){
    this->map = map;
    this->factory_event_on_game = factory_event_on_game;
    this->event_generator = event_generator;
};

//create set wall event
Event* FactoryEventOnMap::createEvent1(){
    return new SetWallEvent(this->map);
};

//create set end game event
Event* FactoryEventOnMap::createEvent2(){
    return new SetWinGameEvent(this->map, this->factory_event_on_game, this->event_generator);
};

//create none event
Event* FactoryEventOnMap::createEvent3(){
    return nullptr;
};

//destruction
FactoryEventOnMap::~FactoryEventOnMap(){
    this->map = nullptr;
    this->factory_event_on_game = nullptr;
    this->event_generator = nullptr;
};
