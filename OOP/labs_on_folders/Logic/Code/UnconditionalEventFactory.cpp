#include "../Headlines/UnconditionalEventFactory.hpp"
#include "../Headlines/FireDamageEvent.hpp"
#include "../Headlines/ChangeMapEvent.hpp"
#include "../Headlines/WinEvent.hpp"

//initialization
UnconditionalEventFactory::UnconditionalEventFactory(Player* player, Map* map, Game* game){
    this->player = player;
    this->map = map;
    this->game = game;
};

//create fire damage event
Event* UnconditionalEventFactory::createEvent1(){
    return new FireDamageEvent(this->player);
};

//create change map event
Event* UnconditionalEventFactory::createEvent2(){
    return new ChangeMapEvent(this->map);
};

//create win event
Event* UnconditionalEventFactory::createEvent3(){
    return new WinEvent(this->game);
};
