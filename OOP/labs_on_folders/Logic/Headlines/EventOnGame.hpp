#pragma once
#include "Event.hpp"
#include "Game.hpp"

class EventOnGame: public Event{
    protected:
        Game* game;
    public:
        //initialization
        EventOnGame(Game* game);

        //destruction
        ~EventOnGame();
};
