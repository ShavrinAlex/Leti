#include "../../../Map/Map.hpp"

template <int magic_number1, int magic_number2>
class SpawnWallsRule{
    public:
        static void apply(Map* map);
};

template <int magic_number1, int magic_number2>
void SpawnWallsRule<magic_number1, magic_number2>::apply(Map* map){
    for (int y = 0; y < map->getHeight(); y++){
        for (int x = 0; x < map->getWidth(); x++){
            if (this->player->pos->x == x && this->player->pos->y == y){
                continue;
            }
            if (rand() % magic_number1 > magic_number2){
                Cell* cell = map->getCell(x, y);
                cell->setWall();
            }
        }
    }
};
