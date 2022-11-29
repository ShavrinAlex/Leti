#pragma once
#include "../EventFactory.hpp"
#include "../../Entities/Player/Player.hpp"
#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"

class FactoryEventOnPlayer: public EventFactory, public GameElement<Log*>{
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
