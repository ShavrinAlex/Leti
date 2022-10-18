#include "EnemiesController.hpp"
#include "../../../Graphic/EntitiesView/EntityView/EntityView.hpp"
#include <iostream>

//initialization
EnemiesController::EnemiesController(Map* map, MapView* map_view){
    this->map = map;
    this->map_view = map_view;
};

//get direction
Direction EnemiesController::getDirection(Entity* enemy){
    Direction dir;
    Position* player_pos = this->map->getPlayerPosition();
    Position* enemy_pos = this->map->getEnemyPosition(enemy);
    if (enemy_pos->x > player_pos->x){
        (enemy_pos->x - player_pos->x) < ((player_pos->x + this->map->getWidth()) - enemy_pos->x) ? dir = Left : dir = Right;
    }
    if (enemy_pos->x < player_pos->x){
        (player_pos->x - enemy_pos->x) < ((enemy_pos->x + this->map->getWidth()) - player_pos->x) ? dir = Right : dir = Left;
    }
    if (enemy_pos->y > player_pos->y){
        (enemy_pos->y - player_pos->y) < ((player_pos->y + this->map->getHeight()) - enemy_pos->y) ? dir = Up : dir = Down;
    }
    if (enemy_pos->y < player_pos->y){
        (player_pos->y - enemy_pos->y) < ((enemy_pos->y + this->map->getHeight()) - player_pos->y) ? dir = Down : dir = Up;
    }
    return dir;
};

//move enemy
void EnemiesController::move(){
    this->time = this->clock.getElapsedTime().asMicroseconds();
    this->clock.restart();
    this->time = time/800;
    this->timer += time;
    if (this->timer >= 2000){
        for (int i = 0; i < map->getEnemies().size(); i++){
            //get enemy and here apperance
            Entity* enemy = map->getEnemies().at(i).entity;
            EntityView* enemy_view = map_view->getEnemiesView().at(i);

            //move
            enemy->setDirection(this->getDirection(enemy));
            this->map->moveEntity(enemy);
            enemy_view->setPosition(map->getEnemyPosition(enemy));

            //shoot
            this->shoot(enemy);
        }
        this->timer = 0;
    }
};

//shoot
void EnemiesController::shoot(Entity* enemy){
    this->map->makeDamage(enemy);
};

//destruction
EnemiesController::~EnemiesController(){
    this->map = nullptr;
};
