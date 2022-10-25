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
Event* FactoryEventOnMap::createEvent1(Mediator<Log*>* mediator){
    SetWallEvent* swe = new SetWallEvent(this->map, this->event_generator);
    swe->setMediator(mediator);
    return swe;
};

//create set end game event
Event* FactoryEventOnMap::createEvent2(Mediator<Log*>* mediator){
    SetWinGameEvent* swge = new SetWinGameEvent(this->map, this->factory_event_on_game, this->event_generator);
    swge->setMediator(mediator);
    return swge;
};

//create none event
Event* FactoryEventOnMap::createEvent3(Mediator<Log*>* mediator){
    return nullptr;
};

//destruction
FactoryEventOnMap::~FactoryEventOnMap(){
    this->map = nullptr;
    this->factory_event_on_game = nullptr;
    this->event_generator = nullptr;
};
