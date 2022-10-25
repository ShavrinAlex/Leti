#pragma once
#include "../../Graphic/GraphicArts/GraphicArts.hpp"
#include "../Utility/Enumerations.hpp"
#include "../MediatorPattern/LogMediator/LogMediator.hpp"
#include "../Controllers/LogController/LogController.hpp"

class Game: public GameElement<Log*>{
    private:
        int map_width;
        int map_height;
        GraphicArts* graphic_arts;
        GameStatus game_status;
        LogController* log_controller;
    public:
        //initialization
        Game();

        //game start
        int startGame();

        //set game status
        void setGameStatus(GameStatus game_status);

        //destruction
        ~Game();
};
