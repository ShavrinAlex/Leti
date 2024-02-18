#pragma once
#include "../EventOnMap/EventOnMap.hpp"
#include "../../../FactoriesPattern/EventFactory.hpp"
#include "../../../Generators/EventGenerator/EventGenerator.hpp"

class SetWinGameEvent: public EventOnMap{
    private:
        GameController* game_controller;
    public:
        //initialization
        SetWinGameEvent(Map* map, GameController* game_controller);

        //execute
        EventStatus execute() override;

        //destruction
        ~SetWinGameEvent();
};
