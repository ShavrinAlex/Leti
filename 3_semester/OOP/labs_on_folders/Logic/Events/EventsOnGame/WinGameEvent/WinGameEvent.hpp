#pragma once
#include "../EventOnGame/EventOnGame.hpp"

class WinGameEvent: public EventOnGame{
    public:
        //initialization
        WinGameEvent(GameController* game_controller);

        //execute
        EventStatus execute() override;
};
