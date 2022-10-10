#include "../Headlines/FactoryEventOnPlayer.hpp"

#include "../Headlines/SetHealthEvent.hpp"
#include "../Headlines/SetArmorEvent.hpp"
#include "../Headlines/SetEnergyEvent.hpp"

//initialization
FactoryEventOnPlayer::FactoryEventOnPlayer(Player* player){
    this->player = player;
};

//create health event
Event* FactoryEventOnPlayer::createEvent1(){
    return new SetHealthEvent(this->player);
};

//create armor event
Event* FactoryEventOnPlayer::createEvent2(){
    return new SetArmorEvent(this->player);
};

//create energy event
Event* FactoryEventOnPlayer::createEvent3(){
    return new SetEnergyEvent(this->player);
};
