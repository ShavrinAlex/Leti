#include "../../../Map/Map.hpp"

template <int magic_number>
class SpawnWallsRule2{
    public:
        static void apply(Map* map);
};

template <int magic_number>
void SpawnWallsRule2<magic_number>::apply(Map* map){
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

            if ((x == 0 || x == map->getWidth()) && (y == 0 || y == map->getHeight()) && magic_number % 2 == 0 && magic_number % 2 == 0){
                map->getCell(x, y)->setWall();
                map->count_wals += 1;
            }
        }
    }
    std::cout<<"end\n";
};
