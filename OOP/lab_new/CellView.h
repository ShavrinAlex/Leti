#include <SFML/Graphics.hpp>
#include "Cell.h"
#define SIDE 98

class CellView{
    private:
        Cell cell;
        int side;
        int x;
        int y;
        sf::RectangleShape* cell_view;

        //change color
        void updateColor();
    public:
        //initialization
        CellView(Cell& cell, int x, int y, int side = SIDE);

        //get draw obgect
        sf::RectangleShape* getDrawObject();
};
