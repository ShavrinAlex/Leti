#pragma once
#include <SFML/Graphics.hpp>
#include "../EntityView/EntityView.hpp"
#include "../../../Logic/Entities/Player/Player.hpp"

class PlayerView: public EntityView{
    private:
        //ammunition scale
        sf::RectangleShape* energy_scale;
        sf::RectangleShape* energy_scale_stroke;

        //armor scale
        sf::RectangleShape* armor_scale;
        sf::RectangleShape* armor_scale_stroke;
        
        //create armor scale
        void createArmorScale();

        //create energy scale
        void createEnergyScale();

        //update energy scale position and size
        void updateEnergyScale();

        //update armor scale position and size
        void updateArmorScale();

    public:
        //initialization
        PlayerView(Player* player, int width, int height, Position* pos, std::string file_image);

        //get energy scale
        sf::RectangleShape* getEnergyScale();

        //get energy scale stroke
        sf::RectangleShape* getEnergyScaleStroke();

        //get armor scale
        sf::RectangleShape* getArmorScale();

        //get armor scale stroke
        sf::RectangleShape* getArmorScaleStroke();

        //update
        void update() override;

        //destruction
        ~PlayerView();
};
