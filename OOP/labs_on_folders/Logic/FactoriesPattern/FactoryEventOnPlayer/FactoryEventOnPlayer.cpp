#include "FactoryEventOnPlayer.hpp"
#include "../../Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.hpp"
#include "../../Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.hpp"
#include "../../Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.hpp"

//initialization
FactoryEventOnPlayer::FactoryEventOnPlayer(Player* player){
    this->player = player;
};

//create health event
Event* FactoryEventOnPlayer::createEvent1(Mediator<Log*>* mediator){
    SetHealthEvent* she = new SetHealthEvent(this->player);
    she->setMediator(mediator);
    return she;
};

//create armor event
Event* FactoryEventOnPlayer::createEvent2(Mediator<Log*>* mediator){
    SetArmorEvent* sae = new SetArmorEvent(this->player);
    sae->setMediator(mediator);
    return sae;
};

//create energy event
Event* FactoryEventOnPlayer::createEvent3(Mediator<Log*>* mediator){
    SetEnergyEvent* see = new SetEnergyEvent(this->player);
    see->setMediator(mediator);
    return see;
};

//destruction
FactoryEventOnPlayer::~FactoryEventOnPlayer(){
    this->player = nullptr;
};
