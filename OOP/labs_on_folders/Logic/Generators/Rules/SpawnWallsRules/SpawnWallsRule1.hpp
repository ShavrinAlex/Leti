#pragma once
#include "../../../Map/Map.hpp"

template <int magic_number>
class SpawnWallsRule1{
    public:
        void apply(Map* map);
};

template <int magic_number>
void SpawnWallsRule1<magic_number>::apply(Map* map){
    for (int y = 0; y < map->getHeight(); y++){
        for (int x = 0; x < map->getWidth(); x++){
            //check if is player position
            if (map->getCell(x, y)->isHerePlayer()){
                continue;
            }

            //check if is enemy position
            if (map->isHereEnemy(x, y)){
                continue;
            }

            //check if is event position
            if (map->getCell(x, y)->getEvent() != nullptr){
                continue;
            }

            if (magic_number*x % 2 == 0 && (y != 0 && y != 1 && y != map->getHeight() - 1 && y != map->getHeight() - 2)){
                map->getCell(x, y)->setWall();
            }
        }
    }
};
