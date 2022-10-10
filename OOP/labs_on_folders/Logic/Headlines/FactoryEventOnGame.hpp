#pragma once
#include "EventFactory.hpp"
#include "Game.hpp"

class FactoryEventOnGame: public EventFactory{
    private:
        Game* game;
    public:
        //initialization
        FactoryEventOnGame(Game* game);

        //create event
        Event* createEvent1() override;
        Event* createEvent2() override;
        Event* createEvent3() override;
};
