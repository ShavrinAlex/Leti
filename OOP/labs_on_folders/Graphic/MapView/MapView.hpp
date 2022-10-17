#pragma once
#include "../../Logic/Map/Map.hpp"
#include "../CellView/CellView.hpp"
#include <vector>

typedef std::vector <std::vector <CellView*>> CellViewMatrix;

class MapView{
    private:
        CellViewMatrix map_view;

        //logic map
        Map* map;

        //create map view
        void createMapView();
        
    public:
        //initialization
        MapView(Map* map);

        //get cell view
        CellView* getCellView(int pos_x, int pos_y);

        //destruction
        ~MapView();
};
