#pragma once
#include "../../../Map/Map.hpp"

template <int pos_x, int pos_y>
class SpawnPlayerRule1{
    public:
        void apply(Map* map);
};

template <int pos_x, int pos_y>
void SpawnPlayerRule1<pos_x, pos_y>::apply(Map* map){
    Position *pos = new Position;
    pos->x = abs(pos_x % map->getWidth());
    pos->y = abs(pos_y % map->getHeight());
    
    while (map->getCell(pos->x, pos->y)->isWall() || map->isHereEnemy(pos->x, pos->y)){
        pos->x = abs((pos->x + 1) % map->getWidth());
        pos->y = abs((pos->y + 1) % map->getHeight());
    }

    map->setPlayerPosition(pos);
};
