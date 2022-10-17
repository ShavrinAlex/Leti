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
        Event* createEvent1() override;
        Event* createEvent2() override;
        Event* createEvent3() override;

        //destruction
        ~FactoryEventOnGame();
};
