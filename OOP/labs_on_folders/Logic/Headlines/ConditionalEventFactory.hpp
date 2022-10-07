#pragma once
#include "EventFactory.hpp"
#include "Player.hpp"

class ConditionalEventFactory: public EventFactory{
    private:
        Player* player;
    public:
        //initialization
        ConditionalEventFactory(Player* player);

        //create event
        Event* createEvent1() override;
        Event* createEvent2() override;
        Event* createEvent3() override;
};
