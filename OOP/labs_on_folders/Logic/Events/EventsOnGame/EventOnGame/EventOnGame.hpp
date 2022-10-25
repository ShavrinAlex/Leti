#pragma once
#include "../../Event.hpp"
#include "../../../Controllers/GameController/GameController.hpp"
#include "../../../Logging/Log/Log.hpp"
#include "../../../MediatorPattern/GameElement/GameElementDescription.hpp"

class EventOnGame: public Event, public GameElement<Log*>{
    protected:
        GameController* game_controller;
    public:
        //initialization
        EventOnGame(GameController* game_controller);

        //destruction
        ~EventOnGame();
};
