#pragma once
#include <SFML/Graphics.hpp>
#include "Position.hpp"
#include "Entity.hpp"
#include "GameElement.hpp"
#include <string>

class EntityView: public GameElement{
    private:
        int width;
        int height;
        std::string file_image;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite* sprite;

        //logic entity
        Entity* entity;

        //update sprite
        void updateSprite();
    public:
        //initialization
        EntityView(Entity* entity, int width, int height, std::string file_image);

        //set position
        void setPosition(Position *player_position);

        //get draw object
        sf::Sprite* getDrawObject();

        //destruction
        ~EntityView();
};
