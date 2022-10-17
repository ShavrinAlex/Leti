#include "FactoryEventOnGame.hpp"
#include "../../Events/EventsOnGame/WinGameEvent/WinGameEvent.hpp"
#include "../../Events/EventsOnGame/EndGameEvent/EndGameEvent.hpp"

//initialization
FactoryEventOnGame::FactoryEventOnGame(GameController* game_controller){
    this->game_controller = game_controller;
};

//create win game event
Event* FactoryEventOnGame::createEvent1(){
    return new WinGameEvent(this->game_controller);
};

//create end game event
Event* FactoryEventOnGame::createEvent2(){
    return new EndGameEvent(this->game_controller);
};

//create none event
Event* FactoryEventOnGame::createEvent3(){
    return nullptr;
};

//destruction
FactoryEventOnGame::~FactoryEventOnGame(){
    this->game_controller = nullptr;
};
