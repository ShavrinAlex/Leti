#pragma once
#include "../EventFactory.hpp"
#include "../../Controllers/GameController/GameController.hpp"

class FactoryEventOnGame: public EventFactory{
    private:
        GameController* game_controller;
    public:
        //initialization
        FactoryEventOnGame(GameController* game_controller);

        //create event
        Event* createEvent1(Mediator<Log*>* mediator) override;
        Event* createEvent2(Mediator<Log*>* mediator) override;
        Event* createEvent3(Mediator<Log*>* mediator) override;

        //destruction
        ~FactoryEventOnGame();
};
