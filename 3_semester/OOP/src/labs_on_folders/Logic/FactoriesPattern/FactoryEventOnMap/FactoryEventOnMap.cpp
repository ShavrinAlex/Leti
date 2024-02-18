#include "FactoryEventOnMap.hpp"
#include "../../Events/EventsOnMap/SetWallEvent/SetWallEvent.hpp"
#include "../../Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.hpp"

//initialization
FactoryEventOnMap::FactoryEventOnMap(Map* map, EventFactory* factory_event_on_game){
    this->map = map;
    this->factory_event_on_game = factory_event_on_game;
};

//create set wall event
Event* FactoryEventOnMap::createEvent1(){
    SetWallEvent* swe = new SetWallEvent(this->map);
    swe->setMediator(this->mediator);
    return swe;
};

//create set end game event
Event* FactoryEventOnMap::createEvent2(){
    SetWinGameEvent* swge = new SetWinGameEvent(this->map, this->factory_event_on_game);
    swge->setMediator(this->mediator);
    return swge;
};

//create none event
Event* FactoryEventOnMap::createEvent3(){
    return nullptr;
};

//destruction
FactoryEventOnMap::~FactoryEventOnMap(){
    this->mediator = nullptr;
    this->map = nullptr;
    this->factory_event_on_game = nullptr;
};
