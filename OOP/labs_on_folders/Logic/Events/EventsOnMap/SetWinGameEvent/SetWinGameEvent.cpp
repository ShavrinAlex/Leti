#include "SetWinGameEvent.hpp"
#include "../../EventsOnGame/WinGameEvent/WinGameEvent.hpp"

//initialization
SetWinGameEvent::SetWinGameEvent(Map* map, GameController* game_controller):EventOnMap(map){
    this->game_controller = game_controller;
};

//execute
EventStatus SetWinGameEvent::execute(){
    Position* position = new Position();
    Cell* cell = nullptr;
    
    do{
        position->x = rand() % this->map->getWidth();
        position->y = rand() % this->map->getHeight();
        cell = this->map->getCell(position->x, position->y);
    } while (cell->isWall() || cell->getEvent() != nullptr);

    Event* event = new WinGameEvent(this->game_controller);
    event->setMediator(this->mediator);
    this->map->getCell(position->x, position->y)->setEvent(event);

    //logging
    Log* log = new Log(Processes, "Event (set win game) was execute");
    this->mediator->send(log);
    delete log;

    return Delete;
};

//destruction
SetWinGameEvent::~SetWinGameEvent(){
    this->game_controller = nullptr;
};
