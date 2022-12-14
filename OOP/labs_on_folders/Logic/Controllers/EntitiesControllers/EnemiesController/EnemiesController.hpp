#pragma once
#include "../EntityController.hpp"
#include "../../../Entities/Entity/Entity.hpp"
#include "../../../../Graphic/EntitiesView/EntityView/EntityView.hpp"
#include "../../../../Graphic/MapView/MapView.hpp"
#include "../../../Map/Map.hpp"
#include "../../../Utility/Enumerations.hpp"

class EnemiesController: public EntityController{
    private:
        Map* map;

        sf::Clock clock;
        float time;
        float timer;

        //get direction
        Direction getDirection(Entity* enemy);
    public:
        //initialization
        EnemiesController(Map* map);

        //move enemy
        void move();

        //shoot
        void shoot(Entity* enemy);

        //take damage
        void takeDamage(int damage, Entity* entity) override;

        //destruction
        ~EnemiesController();
};
