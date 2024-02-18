#pragma once
#include "../Events/Event.hpp"
#include "../ObserverPattern/Observable/Observable.hpp"

class Cell: public Observable{
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

        //set and remove event
        void setEvent(Event* event);
        void removeEvent();

        //get event
        Event* getEvent();

        //check is wall
        bool isWall();

        //set and remove wall
        void setWall();
        void removeWall();

        //check player is here
        bool isHerePlayer();

        //set and remove player
        void setPlayer();
        void removePlayer();
        
        //destruction
        ~Cell();
};
