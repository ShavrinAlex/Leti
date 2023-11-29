#pragma once
#include "../../Event.hpp"
#include "../../../Controllers/GameController/GameController.hpp"

class EventOnGame: public Event{
    protected:
        GameController* game_controller;
    public:
        //initialization
        EventOnGame(GameController* game_controller);

        //destruction
        ~EventOnGame();
};
