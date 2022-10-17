#include "FactoryEventOnPlayer.hpp"
#include "../../Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.hpp"
#include "../../Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.hpp"
#include "../../Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.hpp"

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

//destruction
FactoryEventOnPlayer::~FactoryEventOnPlayer(){
    this->player = nullptr;
};
