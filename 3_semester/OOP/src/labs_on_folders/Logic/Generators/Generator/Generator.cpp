#include "Generator.hpp"

//initialization
Generator::Generator(Map* map){
    this->map = map;
};

//get position random free cell
Position* Generator::getPositionFreeCell(){
    Position* position = new Position();
    Cell* cell = nullptr;
    do{
        position->x = rand() % this->map->getWidth();
        position->y = rand() % this->map->getHeight();
        cell = this->map->getCell(position->x, position->y);
    } while (cell->isWall() || cell->getEvent() != nullptr || cell->isHerePlayer() || this->map->isHereEnemy(position->x, position->y));
    return position;
}

//destruction
Generator::~Generator(){
    this->map = nullptr;
};
