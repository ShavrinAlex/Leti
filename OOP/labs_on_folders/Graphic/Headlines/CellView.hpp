#pragma once
#include <SFML/Graphics.hpp>
#include "../../Logic/Headlines/Cell.hpp"
#include "../../Logic/Headlines/Position.hpp"
#include "../../Logic/Headlines/Observer.hpp"
#define SIDE 98

class CellView: public Observer{
    private:
        int side;
        Position position;
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

        //update
        void update() override;

        //destruction
        ~CellView();
};
