#pragma once
#include "Event.hpp"

class Cell{
    private:
        bool is_wall;
        bool is_here_player;
        Event* event;
    public:
        //initialization
        Cell(bool is_wall = false, bool is_here_player = false);

        //coping
        Cell(const Cell& obj);
        //assignment
        Cell& operator = (const Cell& obj);
        
        //move
        Cell(Cell&& obj);
        Cell& operator = (Cell&& obj);

        //set event
        void setEvent(Event* event);

        //check is wall
        bool isWall();

        //check player is here
        bool isHerePlayer();

        //set player
        void setPlayer();

        //remove player
        void removePlayer();
        //destruction
        ~Cell();
};
