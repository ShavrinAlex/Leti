#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.hpp"
#define SIDE 98

class CellView{
    private:
        int side;
        int pos_x;
        int pos_y;
        sf::RectangleShape* cell_view;

        //logic cell
        Cell* cell;

        //update color
        void updateColor();
    public:
        //initialization
        CellView(Cell* cell, int x, int y, int side = SIDE);

        //get draw obgect
        sf::RectangleShape* getDrawObject();

        //destruction
        ~CellView();
};
