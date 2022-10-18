#pragma once
#include "../../Map/Map.hpp"
#include "../../../Graphic/MapView/MapView.hpp"

class Generator{
    protected:
        Map* map;
        MapView* map_view;

    public:
        //initialization
        Generator(Map* map, MapView* map_view);

        //get position random free cell
        Position* getPositionFreeCell();

        //generate
        void virtual generate(int map_height, int map_width) = 0;

        //destruction
        ~Generator();
};