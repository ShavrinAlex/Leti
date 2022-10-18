#include "Generator.hpp"

//initialization
Generator::Generator(Map* map, MapView* map_view){
    this->map = map;
    this->map_view = map_view;
};

//get position random free cell
Position* Generator::getPositionFreeCell(){
    Position* position = new Position();
    Cell* cell = nullptr;
    do{
        position->x = rand() % this->map->getWidth();
        position->y = rand() % this->map->getHeight();
        cell = this->map->getCell(position->x, position->y);
    } while (cell->isWall() || cell->getEvent() != nullptr || cell->isHerePlayer() || this->map->isHereEnemy(position));
    return position;
}

//destruction
Generator::~Generator(){
    this->map = nullptr;
    this->map_view = nullptr;
};
