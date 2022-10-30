#pragma once
#include "../EntityController.hpp"
#include "../../../Entities/Player/Player.hpp"
#include "../../../../Graphic/EntitiesView/PlayerView/PlayerView.hpp"
#include "../../../Map/Map.hpp"
#include "../../../Utility/Enumerations.hpp"

class PlayerController: public EntityController{
    private:
        Player* player;
        
        Map* map;
        PlayerView* player_view;
    public:
        //initialization
        PlayerController(Player* player, Map* map, PlayerView* player_view);

        //move player
        void move(Direction dir);

        //shoot
        void shoot();

        //take damage
        void takeDamage(int damage, Entity* entity) override;

        //destruction
        ~PlayerController();
};
