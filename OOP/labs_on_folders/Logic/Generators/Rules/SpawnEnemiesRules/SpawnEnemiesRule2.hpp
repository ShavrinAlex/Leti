#include "../../../Map/Map.hpp"

template <int magic_number, int count>
class SpawnEnemiesRule2{
    public:
        static void apply(Map* map);
};

template <int magic_number, int count>
void SpawnEnemiesRule2<magic_number, count>::apply(Map* map){
    Position* position = new Position();
    Cell* cell = nullptr;

    for (int i = 1; i <= count; i++){
        int tmp_number = magic_number;
        //generate position
        do {
            position->x = tmp_number * i % map->getWidth();
            position->y = tmp_number * i % map->getHeight();
            cell = map->getCell(position->x, position->y);
            tmp_number++;
        } while (cell->isWall() || cell->isHerePlayer() || cell->getEvent() != nullptr);

        //create enemy
        Entity* ent = new Entity();
        ent->setSpeed(1);

        //set enemy
        map->addEnemy(ent, position);
    }
    std::cout<<"end\n";
};