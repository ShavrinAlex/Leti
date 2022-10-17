#pragma once
#include "../../Graphic/GraphicArts/GraphicArts.hpp"
#include "../Utility/Enumerations.hpp"

class Game{
    private:
        int map_width;
        int map_height;
        GraphicArts* graphic_arts;
        GameStatus game_status;
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
