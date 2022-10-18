#include "SetWallEvent.hpp"
#include "../../../Cell/Cell.hpp"

//initialization
SetWallEvent::SetWallEvent(Map* map, Generator* generator):EventOnMap(map, generator){};

//execute
EventStatus SetWallEvent::execute(){
    Position* pos = this->generator->getPositionFreeCell();
    Cell* cell = this->map->getCell(pos->x, pos->y);
    cell->setWall();

    return Delete;
};
