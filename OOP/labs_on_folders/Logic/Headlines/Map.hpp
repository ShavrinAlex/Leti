#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.hpp"
#include "Position.hpp"
#include "Enumerations.hpp"
#include "GameElement.hpp"
#include <vector>

typedef std::vector < std::vector <Cell*> > CellMatrix;

class Map: public GameElement{
    private:
        Position player_position;
        int width, height;
        CellMatrix map;

        //create map
        void createMap();
    public:
        //initialization
        Map();
        Map(int width, int height); 

        //coping
        Map(const Map& obj);
        //assignment
        Map& operator = (const Map& obj);

        //move
        Map(Map&& obj);
        Map& operator = (Map&& obj);

        //get size
        int getHeight();
        int getWidth();

        //get cell
        Cell* getCell(int pos_x, int pos_y);

        //set player position
        void setPlayerPosition(Position* next_player_position);

        //get player position
        Position* getPlayerPosition();

        //calculate next player position
        Position* calculateNextPlayerPosition(int speed, Direction direction);

        //destruction
        ~Map();
};
