#include "SetWallEvent.hpp"
#include "../../../Cell/Cell.hpp"

//initialization
SetWallEvent::SetWallEvent(Map* map, Generator* generator):EventOnMap(map, generator){};

//execute
EventStatus SetWallEvent::execute(){
    Position* pos = this->generator->getPositionFreeCell();
    Cell* cell = this->map->getCell(pos->x, pos->y);
    cell->setWall();

    //logging
    Log* log = new Log(Processes, "Event (set wall) was execute");
    this->mediator->send(log);
    delete log;

    return Delete;
};
