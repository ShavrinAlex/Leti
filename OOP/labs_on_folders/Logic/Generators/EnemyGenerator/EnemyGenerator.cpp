#include "EnemyGenerator.hpp"
#include "../../Entities/Entity/Entity.hpp"
#include "../../../Graphic/EntitiesView/EntityView/EntityView.hpp"

#define ENEMY_WIDTH 98
#define ENEMY_HEIGHT 98
#define ENEMY_IMAGE "./Graphic/Images/Entities/Player/hero1.png"

//initialization
EnemyGenerator::EnemyGenerator(Map* map, MapView* map_view):Generator(map, map_view){};

//geterate enemy
void EnemyGenerator::generateEnemy(){
    Position* position = this->getPositionFreeCell();
    Entity* ent = new Entity();
    ent->setSpeed(1);
    
    //set enemy
    (this->map)->addEnemy(ent, position);

    //set enemy view
    EntityView* ev = new EntityView(ent, ENEMY_WIDTH, ENEMY_HEIGHT, position, ENEMY_IMAGE);
    (this->map_view)->addEnemyView(ev);
};

//generate all enemy
void EnemyGenerator::generate(int map_height, int map_width){
    int map_size = map_height * map_width;
    
    for (int i = 0; i < (map_size / 100.0) * 5; i++){
        this->generateEnemy();
    }
};
