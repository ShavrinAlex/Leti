#pragma once
#include "../../../Map/Map.hpp"

template <int core>
class SpawnPlayerRule2{
    public:
        void apply(Map* map);
};

template <int core>
void SpawnPlayerRule2<core>::apply(Map* map){
    srand(core);

    Position *pos = new Position;
    pos->x = rand() % map->getWidth();
    pos->y = rand() % map->getHeight();

    while (map->getCell(pos->x, pos->y)->isWall() || map->isHereEnemy(pos->x, pos->y)){
            pos->x = rand() % map->getWidth();
            pos->y = rand() % map->getHeight();
    }

    map->setPlayerPosition(pos);
};