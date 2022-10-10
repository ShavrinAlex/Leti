#include "../Headlines/FactoryEventOnGame.hpp"

#include "../Headlines/WinGameEvent.hpp"
#include "../Headlines/EndGameEvent.hpp"

//initialization
FactoryEventOnGame::FactoryEventOnGame(Game* game){
    this->game = game;
};

//create win game event
Event* FactoryEventOnGame::createEvent1(){
    return new WinGameEvent(this->game);
};

//create end game event
Event* FactoryEventOnGame::createEvent2(){
    return new EndGameEvent(this->game);
};

//create none event
Event* FactoryEventOnGame::createEvent3(){
    return nullptr;
};
