#pragma once
#include <SFML/Graphics.hpp>
#include "../Headlines/EntityView.hpp"
#include "../../Logic/Headlines/Player.hpp"

class PlayerView: public EntityView{
    private:
        //ammunition scale
        sf::RectangleShape* ammunition_scale;
        sf::RectangleShape* ammunition_scale_stroke;

        //armor scale
        sf::RectangleShape* armor_scale;
        sf::RectangleShape* armor_scale_stroke;
        
        //create armor scale
        void createArmorScale();

        //create ammunition scale
        void createAmmunitionScale();

        //update ammunition scale position and size
        void updateAmmunitionScale();

        //update armor scale position and size
        void updateArmorScale();

    public:
        //initialization
        PlayerView(Player* player, int width, int height, Position* pos, std::string file_image);

        //get ammunition scale
        sf::RectangleShape* getAmmunitionScale();

        //get ammunition scale
        sf::RectangleShape* getAmmunitionScaleStroke();

        //get armor scale
        sf::RectangleShape* getArmorScale();

        //get armor scale
        sf::RectangleShape* getArmorScaleStroke();

        //update
        void update() override;
};
