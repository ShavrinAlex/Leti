#include "PlayerController.hpp"
#define SHOOT_ENERGY 25

//initialization
PlayerController::PlayerController(Player* player, Map* map){
    this->player = player;
    this->map = map;
};

//move player
void PlayerController::move(Direction dir){
    this->player->setDirection(dir);
    this->map->moveEntity(this->player);
};

//shoot
void PlayerController::shoot(){
    //erraise energy
    int player_energy = this->player->getEnergy();
    if (player_energy >= SHOOT_ENERGY){
        this->player->setEnergy(player_energy - SHOOT_ENERGY);

        this->map->makeDamage(this->player);

        //logging
        Log* log = new Log(Processes, "Player hit");
        this->mediator->send(log);
        delete log;
    } else{
        //logging
        Log* log = new Log(Errors, "Error!!! Player tried to hit without energy");
        this->mediator->send(log);
        delete log;
    }
};

//take damage
void PlayerController::takeDamage(int damage, Entity* entity){
    if (entity == this->player){
        //check armor
        if (this->player->getArmor()){
           this->player->removeArmor();
        } else{
            int health = this->player->getHealth();

            //damage player
            if (health - damage <= 0){
                this->player->setHealth(0);

            } else{
                this->player->setHealth(health - damage);
            }
            //logging
            Log* log = new Log(Processes, "Player taked damage");
            this->mediator->send(log);
            delete log;
        }
    }
};

//destruction
PlayerController::~PlayerController(){
    this->player = nullptr;
    this->map = nullptr;
};
