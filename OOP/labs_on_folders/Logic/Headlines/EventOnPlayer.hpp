#pragma once
#include "Event.hpp"
#include "Player.hpp"

class EventOnPlayer: public Event{
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
