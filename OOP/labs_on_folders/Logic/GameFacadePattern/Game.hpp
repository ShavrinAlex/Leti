#pragma once
#include "../../Graphic/GraphicArts/GraphicArts.hpp"
#include "../Utility/Enumerations.hpp"
#include "../MediatorPattern/LogMediator/LogMediator.hpp"
#include "../Controllers/LogController/LogController.hpp"

class Game: public GameElement<Log*>{
    private:
        int map_width;
        int map_height;
        Levels level;
        GraphicArts* graphic_arts;
        GameStatus game_status;
        LogController* log_controller;
    public:
        //initialization
        Game();

        //crreate level
        Map* createLevel(GameController* game_controller, Player* player);

        //game start
        int startGame();

        //set game status
        void setGameStatus(GameStatus game_status);

        //destruction
        ~Game();
};
