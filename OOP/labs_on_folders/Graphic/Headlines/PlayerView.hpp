#pragma once
#include <SFML/Graphics.hpp>
#include "../Headlines/EntityView.hpp"
#include "../../Logic/Headlines/Player.hpp"

class PlayerView: public EntityView{
    private:
        //ammunition scale
        sf::RectangleShape* ammunition_scale;
        sf::RectangleShape* ammunition_scale_stroke;

        //update ammunition scale position and size
        void updateAmmunitionScale();
    public:
        //initialization
        PlayerView(Player* player, int width, int height, Position* pos, std::string file_image);

        //get ammunition scale
        sf::RectangleShape* getAmmunitionScale();

        //get ammunition scale
        sf::RectangleShape* getAmmunitionScaleStroke();

        //update
        void update() override;
};
