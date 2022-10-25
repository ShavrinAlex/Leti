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
        Event* createEvent1(Mediator<Log*>* mediator) override;
        Event* createEvent2(Mediator<Log*>* mediator) override;
        Event* createEvent3(Mediator<Log*>* mediator) override;

        //destruction
        ~FactoryEventOnPlayer();
};
