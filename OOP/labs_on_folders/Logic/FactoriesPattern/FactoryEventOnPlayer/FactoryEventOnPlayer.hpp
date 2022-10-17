#pragma once
#include "../EventFactory.hpp"
#include "../../Entities/Player/Player.hpp"

class FactoryEventOnPlayer: public EventFactory{
    private:
        Player* player;
    public:
        //initialization
        FactoryEventOnPlayer(Player* player);

        //create event
        Event* createEvent1() override;
        Event* createEvent2() override;
        Event* createEvent3() override;

        //destruction
        ~FactoryEventOnPlayer();
};
