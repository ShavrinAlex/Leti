#include "Generator.hpp"

//initialization
Generator::Generator(Map* map, MapView* map_view){
    this->map = map;
    this->map_view = map_view;
};

//check enemy on cell
bool Generator::isHereEnemy(Position* pos){
    if (this->map->getEnemies().size() == 0){
        return false;
    }
    for (int i = 0; i < this->map->getEnemies().size(); i++){
        if ((this->map)->getEnemies().at(i).pos->x == pos->x && (this->map)->getEnemies().at(i).pos->y == pos->y){
            return true;
        }
    }
    return false;
};

//get position random free cell
Position* Generator::getPositionFreeCell(){
    Position* position = new Position();
    Cell* cell = nullptr;
    do{
        position->x = rand() % this->map->getWidth();
        position->y = rand() % this->map->getHeight();
        cell = this->map->getCell(position->x, position->y);
    } while (cell->isWall() || cell->isHerePlayer() || cell->getEvent() != nullptr || this->isHereEnemy(position));
    return position;
}

//destruction
Generator::~Generator(){
    this->map = nullptr;
    this->map_view = nullptr;
};
