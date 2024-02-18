#pragma once
#include "../EventFactory.hpp"
#include "../../Controllers/GameController/GameController.hpp"
#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"

class FactoryEventOnGame: public EventFactory, public GameElement<Log*>{
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
