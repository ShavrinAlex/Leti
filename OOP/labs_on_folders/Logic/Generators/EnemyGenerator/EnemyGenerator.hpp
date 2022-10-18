#pragma once
#include "../Generator/Generator.hpp"

class EnemyGenerator: public Generator{
    public:
        //initialization
        EnemyGenerator(Map* map, MapView* map_view);

        //geterate enemy
        void generateEnemy();

        //generate all enemy
        void generate(int map_height, int map_width) override;
};
