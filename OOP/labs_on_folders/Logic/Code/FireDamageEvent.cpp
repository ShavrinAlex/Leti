#include "../Headlines/FireDamageEvent.hpp"
#define MIN_HEALTH 0

//initialization
FireDamageEvent::FireDamageEvent(Player* player, int damage){
    this->damage = damage;
    this->player = player;
};

//execute
void FireDamageEvent::execute(){
    int player_health = player->getHealth() - this->damage;

    if (player_health < MIN_HEALTH){
        player->setHealth(0);
    } else{
        player->setHealth(player_health);
    }
};
