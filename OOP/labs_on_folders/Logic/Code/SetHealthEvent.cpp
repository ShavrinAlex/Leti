#include "../Headlines/SetHealthEvent.hpp"
#define MAX_HEALTH 100

//initialization
SetHealthEvent::SetHealthEvent(Player* player, int health):EventOnPlayer(player){
    this->health = health;
};

//check conditional
bool SetHealthEvent::checkConditional(){
    return this->player->getHealth() != MAX_HEALTH;
};

//execute
EventStatus SetHealthEvent::execute(){
    //check conditional
    if (this->checkConditional()){
        int player_health = player->getHealth() + health;

        if (player_health > MAX_HEALTH){
            player->setHealth(MAX_HEALTH);
        } else{
            player->setHealth(player_health);
        }
        return DELETE;
    }
    return LEAVE;
};
