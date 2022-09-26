#pragma once

class Cell{
    private:
        bool is_wall;
        bool is_here_player;
    public:
        //initialization
        Cell(bool is_wall = false, bool is_here_player = false);

        //check is wall
        bool isWall();

        //check player is here
        bool isHerePlayer();

        //set player
        void setPlayer(bool is_here_player);
};
