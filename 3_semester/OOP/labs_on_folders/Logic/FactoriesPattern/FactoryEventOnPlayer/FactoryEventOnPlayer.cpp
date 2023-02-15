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
    SetHealthEvent* she = new SetHealthEvent(this->player);
    she->setMediator(this->mediator);
    return she;
};

//create armor event
Event* FactoryEventOnPlayer::createEvent2(){
    SetArmorEvent* sae = new SetArmorEvent(this->player);
    sae->setMediator(this->mediator);
    return sae;
};

//create energy event
Event* FactoryEventOnPlayer::createEvent3(){
    SetEnergyEvent* see = new SetEnergyEvent(this->player);
    see->setMediator(this->mediator);
    return see;
};

//destruction
FactoryEventOnPlayer::~FactoryEventOnPlayer(){
    this->player = nullptr;
};
