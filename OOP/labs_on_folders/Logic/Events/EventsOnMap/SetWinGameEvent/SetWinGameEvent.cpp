#include "SetWinGameEvent.hpp"

//initialization
SetWinGameEvent::SetWinGameEvent(Map* map, EventFactory* factory_event_on_game, EventGenerator* event_generator):EventOnMap(map, event_generator){
    this->factory_event_on_game = factory_event_on_game;
    this->event_generator = event_generator;
};

//execute
EventStatus SetWinGameEvent::execute(){
    Position* pos = this->generator->getPositionFreeCell();
    this->event_generator->generateWinGameEvent(pos, factory_event_on_game);

    //logging
    Log* log = new Log(Processes, "Event (set win game) was execute");
    this->mediator->send(log);
    delete log;

    return Delete;
};

//destruction
SetWinGameEvent::~SetWinGameEvent(){
    this->event_generator = nullptr;
    this->factory_event_on_game = nullptr;
};
