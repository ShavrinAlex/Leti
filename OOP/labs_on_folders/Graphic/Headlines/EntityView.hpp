#pragma once
#include <SFML/Graphics.hpp>
#include "../../Logic/Headlines/Position.hpp"
#include "../../Logic/Headlines/Entity.hpp"
#include "../../Logic/Headlines/GameElement.hpp"
#include <string>

class EntityView: public GameElement{
    protected:
        //entity
        int width;
        int height;
        Position position;

        //sprite
        std::string file_image;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite* sprite;

        //health scale
        sf::RectangleShape* health_scale;
        sf::RectangleShape* health_scale_stroke;

        //logic entity
        Entity* entity;

        //update sprite position and direction
        void updateSprite();

        //update health scale position and size
        void updateHealthScale();
    public:
        //initialization
        EntityView(Entity* entity, int width, int height, Position* pos, std::string file_image);

        //set position
        void setPosition(Position *player_position);

        //get sprite
        sf::Sprite* getSprite();

        //get health scale
        sf::RectangleShape* getHealthScale();

        //get health scale
        sf::RectangleShape* getHealthScaleStroke();

        //destruction
        ~EntityView();
};
