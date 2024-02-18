#pragma once
#include "../../Map/Map.hpp"
#include "../../../Graphic/MapView/MapView.hpp"
#include "../../MediatorPattern/Mediator.hpp"

class Generator{
    protected:
        Map* map;
    public:
        //initialization
        Generator(Map* map);

        //get position random free cell
        Position* getPositionFreeCell();

        //generate
        void virtual generate(int map_height, int map_width) = 0;

        //destruction
        ~Generator();
};