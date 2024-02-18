#pragma once
#include "../../../Map/Map.hpp"

template <int magic_number, int count>
class SpawnEnemiesRule2{
    public:
        void apply(Map* map);
};

template <int magic_number, int count>
void SpawnEnemiesRule2<magic_number, count>::apply(Map* map){
    for (int i = 1; i <= count; i++){
        int tmp_number = magic_number;
        Position* position = new Position();
        Cell* cell = nullptr;
        bool is_error = false;

        //generate position
        do {
            position->x = (tmp_number * i) % map->getWidth();
            position->y = (tmp_number + i) % map->getHeight();
            cell = map->getCell(position->x, position->y);
            tmp_number++;
            if (tmp_number > 10 * magic_number){
                is_error = true;
                break;
            }
        } while (cell->isWall() || cell->isHerePlayer() || map->isHereEnemy(position->x, position->y));

        if (!is_error){
            //create enemy
            Entity* ent = new Entity();
            ent->setSpeed(1);

            //set enemy
            map->addEnemy(ent, position);
        }
    }
};