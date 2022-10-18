#include "PlayerController.hpp"
#define SHOOT_ENERGY 25

//initialization
PlayerController::PlayerController(Player* player, Map* map, PlayerView* player_view){
    this->player = player;
    this->map = map;
    this->player_view = player_view;
};

//move player
void PlayerController::move(Direction dir){
    this->time = this->clock.getElapsedTime().asMicroseconds();
    this->clock.restart();
    this->time = time/800;
    this->timer += time;
    if (this->timer >= 350){
        this->player->setDirection(dir);
        this->map->moveEntity(this->player);
        this->player_view->setPosition(map->getPlayerPosition());
        this->timer = 0;
    }
};

//shoot
void PlayerController::shoot(){
    this->time = this->clock.getElapsedTime().asMicroseconds();
    this->clock.restart();
    this->time = time/800;
    this->timer += time;
    if (this->timer >= 350){
        int player_energy = this->player->getEnergy();
        if (player_energy >= SHOOT_ENERGY){
            this->player->setEnergy(player_energy - SHOOT_ENERGY);
            this->map->makeDamage(this->player);
            this->timer = 0;
        }
    }
};

//destruction
PlayerController::~PlayerController(){
    this->player = nullptr;
    this->map = nullptr;
    this->player_view = nullptr;
};
