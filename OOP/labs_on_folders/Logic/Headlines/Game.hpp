#pragma once
#include "../../Graphic/Headlines/GraphicArts.hpp"
#include "Enumerations.hpp"

class Game{
    private:
        int map_width;
        int map_height;
        GraphicArts* graphic_arts;
        GameStatus game_status;

        //check end game
        void checkEndGame(Player* player);
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
