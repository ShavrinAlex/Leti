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
        Log* log;
        //erraise energy
        int player_energy = this->player->getEnergy();
        if (player_energy >= SHOOT_ENERGY){
            this->player->setEnergy(player_energy - SHOOT_ENERGY);

            this->map->makeDamage(this->player);
            this->timer = 0;

            //logging
            log = new Log(Processes, "Player hit");
            this->mediator->send(log);
        } else{
            //logging
            log = new Log(Errors, "Error!!! Player tried to hit without energy");
            this->mediator->send(log);
            this->timer = 0;
        }
        delete log;
    }
};

//take damage
void PlayerController::takeDamage(int damage, Entity* entity){
    if (entity == this->player){
        Log* log;
        //check armor
        //if (this->player->getArmor()){
        //    this->player->removeArmor();
        //} else{
            int health = this->player->getHealth();

            //damage player
            if (health - damage <= 0){
                this->player->setHealth(0);

            } else{
                this->player->setHealth(health - damage);
            }
            //logging
            log = new Log(Processes, "Player taked damage");
            this->mediator->send(log);
        //}
        delete log;
    }
};

//destruction
PlayerController::~PlayerController(){
    this->player = nullptr;
    this->map = nullptr;
    this->player_view = nullptr;
};
