#include "PlayerController.hpp"

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
        this->map->setPlayerPosition(map->calculateNextPlayerPosition(player->getSpeed(), dir));
        this->player_view->setPosition(map->getPlayerPosition());
        this->timer = 0;
    }
};

//destruction
PlayerController::~PlayerController(){
    this->player = nullptr;
    this->map = nullptr;
    this->player_view = nullptr;
};
