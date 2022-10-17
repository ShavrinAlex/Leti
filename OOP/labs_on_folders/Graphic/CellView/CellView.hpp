#pragma once
#include <SFML/Graphics.hpp>
#include "../../Logic/Cell/Cell.hpp"
#include "../../Logic/Utility/Position.hpp"
#include "../../Logic/ObserverPattern/Observer.hpp"
#include "../EventView/EventView.hpp"
#define SIDE 98

class CellView: public Observer{
    private:
        int side;
        Position position;
        sf::RectangleShape* cell_view;

        //logic cell
        Cell* cell;

        //event view
        EventView* event_view;

        //update color
        void updateColor();

        //update event view
        void updateEventView();
    public:
        //initialization
        CellView(Cell* cell, int x, int y, int side = SIDE);

        //get draw obgect
        sf::RectangleShape* getDrawObject();

        //set and remove event view
        void setEventView(EventView* ev);
        void removeEventView();

        //get event view
        EventView* getEventView();

        //update
        void update() override;

        //destruction
        ~CellView();
};
