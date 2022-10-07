#include "../Headlines/ChangeMapEvent.hpp"
#include "../Headlines/Cell.hpp"

//initialization
ChangeMapEvent::ChangeMapEvent(Map* map){
    this->map = map;
};

//execute
void ChangeMapEvent::execute(){
    int x, y;
    Cell* cell;
    do{
        x = rand() % this->map->getWidth();
        y = rand() % this->map->getHeight();
        cell = this->map->getCell(x, y);
    } while(cell->getEvent() != nullptr || cell->isHerePlayer());

    cell->isWall() ? cell->removeWall() : cell->setWall();
};
