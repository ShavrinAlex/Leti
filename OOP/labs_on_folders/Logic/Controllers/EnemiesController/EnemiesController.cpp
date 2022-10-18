#include "EnemiesController.hpp"
#include "../../../Graphic/EntitiesView/EntityView/EntityView.hpp"
#include <iostream>

//initialization
EnemiesController::EnemiesController(Map* map, MapView* map_view){
    this->map = map;
    this->map_view = map_view;
};

//get random direction
Direction EnemiesController::getRandomDirection(){
    return (Direction)(rand() % 4);
};

//move enemy
void EnemiesController::move(){
    this->time = this->clock.getElapsedTime().asMicroseconds();
    this->clock.restart();
    this->time = time/800;
    this->timer += time;
    if (this->timer >= 2000){
        for (int i = 0; i < map->getEnemies().size(); i++){
            Entity* enemy = map->getEnemies().at(i).entity;
            EntityView* enemy_view = map_view->getEnemiesView().at(i);
            enemy->setDirection(this->getRandomDirection());
            this->map->moveEntity(enemy);
            enemy_view->setPosition(map->getEnemyPosition(enemy));
        }
        this->timer = 0;
    }
};

//destruction
EnemiesController::~EnemiesController(){
    this->map = nullptr;
};
