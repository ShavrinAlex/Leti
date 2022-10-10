#include "../Headlines/SetWallEvent.hpp"
#include "../Headlines/Cell.hpp"
#include <iostream>

//initialization
SetWallEvent::SetWallEvent(Map* map):EventOnMap(map){};

//execute
EventStatus SetWallEvent::execute(){
    int x, y;
    Cell* cell;
    do{
        x = rand() % this->map->getWidth();
        y = rand() % this->map->getHeight();
        cell = this->map->getCell(x, y);
    } while(cell->getEvent() != nullptr || cell->isHerePlayer() || cell->isWall());
    cell->setWall();
    return DELETE;
};
