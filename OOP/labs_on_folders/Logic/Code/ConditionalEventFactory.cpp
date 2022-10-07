#include "../Headlines/ConditionalEventFactory.hpp"
#include "../Headlines/SetHealthEvent.hpp"
#include "../Headlines/SetArmorEvent.hpp"
#include "../Headlines/SetEnergyEvent.hpp"

//initialization
ConditionalEventFactory::ConditionalEventFactory(Player* player){
    this->player = player;
};

//create health event
Event* ConditionalEventFactory::createEvent1(){
    return new SetHealthEvent(this->player);
};

//create armor event
Event* ConditionalEventFactory::createEvent2(){
    return new SetArmorEvent(this->player);
};

//create energy event
Event* ConditionalEventFactory::createEvent3(){
    return new SetEnergyEvent(this->player);
};
