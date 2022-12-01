#include "../../../Map/Map.hpp"

template <int core, int precent>
class SpawnEnemiesRule1{
    public:
        static void apply(Map* map);
};

template <int core, int precent>
void SpawnEnemiesRule1<core, precent>::apply(Map* map){
    srand(core);
    int map_size = map->getHeight() * map->getWidth();
    
    for (int i = 0; i < (map_size / 100.0) * (precent % 100); i++){
        //generate random position
        Position* position = new Position();
        Cell* cell = nullptr;
        do{
            position->x = rand() % map->getWidth();
            position->y = rand() % map->getHeight();
            cell = map->getCell(position->x, position->y);
        } while (cell->isWall() || cell->isHerePlayer() || map->isHereEnemy(position->x, position->y));

        //create enemy
        Entity* ent = new Entity();
        ent->setSpeed(1);

        //set enemy
        map->addEnemy(ent, position);
    }
};