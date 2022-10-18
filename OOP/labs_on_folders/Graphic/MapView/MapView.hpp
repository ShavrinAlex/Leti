#pragma once
#include "../../Logic/Map/Map.hpp"
#include "../CellView/CellView.hpp"
#include "../EntitiesView/EntityView/EntityView.hpp"
#include <vector>

typedef std::vector <std::vector <CellView*>> CellViewMatrix;
typedef std::vector <EntityView*> EnemiesView;

class MapView{
    private:
        CellViewMatrix map_view;
        EnemiesView enemies_view;

        //logic map
        Map* map;

        //create map view
        void createMapView();
        
    public:
        //initialization
        MapView(Map* map);

        //add enemy view
        void addEnemyView(EntityView* enemy_view);

        //get enemies view
        EnemiesView getEnemiesView();

        //get cell view
        CellView* getCellView(int pos_x, int pos_y);

        //destruction
        ~MapView();
};
