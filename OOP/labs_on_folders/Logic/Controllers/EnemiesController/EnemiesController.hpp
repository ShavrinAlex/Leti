#pragma once
#include "../../Entities/Entity/Entity.hpp"
#include "../../../Graphic/EntitiesView/EntityView/EntityView.hpp"
#include "../../../Graphic/MapView/MapView.hpp"
#include "../../Map/Map.hpp"
#include "../../Utility/Enumerations.hpp"

class EnemiesController{
    private:
        Map* map;
        MapView* map_view;
        sf::Clock clock;
        float time;
        float timer;

        //get direction
        Direction getDirection(Entity* enemy);

        
    public:
        //initialization
        EnemiesController(Map* map, MapView* map_view);

        //move enemy
        void move();

        //shoot
        void shoot(Entity* enemy);

        //destruction
        ~EnemiesController();
};
