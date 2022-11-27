#pragma once
#include "../../Logic/Map/Map.hpp"
#include "../CellView/CellView.hpp"
#include "../EntitiesView/EntityView/EntityView.hpp"
#include "../EntitiesView/PlayerView/PlayerView.hpp"
#include "../../Logic/ObserverPattern/Observer.hpp"
#include <vector>

typedef std::vector <std::vector <CellView*>> CellViewMatrix;
typedef std::vector <EntityView*> EnemiesView;

typedef std::vector <EntityElem> Enemies;

class MapView: public Observer{
    private:
        PlayerView* player_view;
        CellViewMatrix map_view;
        EnemiesView enemies_view;

        //logic map
        Map* map;

        //create map view
        void createMapView();
        
    public:
        //initialization
        MapView(Map* map);

        //set player view
        void setPlayerView(PlayerView* player_view);

        //get player view
        PlayerView* getPlayerView();

        //add enemy view
        void addEnemyView(EntityView* enemy_view);

        //remove enemy view
        void removeEnemyView(int index);

        //get enemies view
        EnemiesView getEnemiesView();

        //get cell view
        CellView* getCellView(int pos_x, int pos_y);

        //update
        void update() override;

        //destruction
        ~MapView();
};
