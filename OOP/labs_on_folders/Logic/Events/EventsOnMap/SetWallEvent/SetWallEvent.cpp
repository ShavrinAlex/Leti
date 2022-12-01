#include "SetWallEvent.hpp"
#include "../../../Cell/Cell.hpp"

//initialization
SetWallEvent::SetWallEvent(Map* map):EventOnMap(map){};

//execute
EventStatus SetWallEvent::execute(){
    Position* position = new Position();
    Cell* cell = nullptr;
    do{
        position->x = rand() % this->map->getWidth();
        position->y = rand() % this->map->getHeight();
        cell = this->map->getCell(position->x, position->y);
    } while (cell->isWall() || cell->getEvent() != nullptr || cell->isHerePlayer() || this->map->isHereEnemy(position->x, position->y));
    cell->setWall();

    //logging
    Log* log = new Log(Processes, "Event (set wall) was execute");
    this->mediator->send(log);
    delete log;

    return Delete;
};
