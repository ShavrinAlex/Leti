#include "FactoryEventOnGame.hpp"
#include "../../Events/EventsOnGame/WinGameEvent/WinGameEvent.hpp"
#include "../../Events/EventsOnGame/EndGameEvent/EndGameEvent.hpp"

//initialization
FactoryEventOnGame::FactoryEventOnGame(GameController* game_controller){
    this->game_controller = game_controller;
};

//create win game event
Event* FactoryEventOnGame::createEvent1(Mediator<Log*>* mediator){
    WinGameEvent* wge =  new WinGameEvent(this->game_controller);
    wge->setMediator(mediator);
    return wge;
};

//create end game event
Event* FactoryEventOnGame::createEvent2(Mediator<Log*>* mediator){
    EndGameEvent* ege = new EndGameEvent(this->game_controller);
    ege->setMediator(mediator);
    return ege;
};

//create none event
Event* FactoryEventOnGame::createEvent3(Mediator<Log*>* mediator){
    return nullptr;
};

//destruction
FactoryEventOnGame::~FactoryEventOnGame(){
    this->game_controller = nullptr;
};
