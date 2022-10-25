#pragma once
#include "../../Event.hpp"
#include "../../../Entities/Player/Player.hpp"
#include "../../../Logging/Log/Log.hpp"
#include "../../../MediatorPattern/GameElement/GameElementDescription.hpp"

class EventOnPlayer: public Event, public GameElement<Log*>{
    protected:
        Player* player;

        //check conditional
        virtual bool checkConditional() = 0;
    public:
        //initialization
        EventOnPlayer(Player* player);

        //destruction
        ~EventOnPlayer();
};
