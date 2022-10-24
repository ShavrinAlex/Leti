#include "EnemiesController.hpp"
#include <iostream>
#define ENEMY_DAMAGE 25

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
        for (size_t i = 0; i < map->getEnemies().size(); i++){
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

//take damage
void EnemiesController::takeDamage(int damage, Entity* entity){
    auto enemies = this->map->getEnemies();
    for (size_t i = 0; i < enemies.size(); i++){
        if (enemies.at(i).entity == entity){
            int health = enemies.at(i).entity->getHealth();
            //damage enemy
            if (health - damage <= 0){
                enemies.at(i).entity->setHealth(0);

                //remove enemy
                this->map->removeEnemy(enemies.at(i).entity);
                this->map_view->removeEnemyView(i);
            } else{
                enemies.at(i).entity->setHealth(health - damage);
            }
        }
    }
};

//destruction
EnemiesController::~EnemiesController(){
    this->map = nullptr;
};
