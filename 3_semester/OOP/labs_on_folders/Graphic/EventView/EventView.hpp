#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Logic/Utility/Position.hpp"
#define CELL_SIDE 98

class EventView{
    private:
        //event
        int width;
        int height;
        Position position;

        //sprite
        std::string file_image;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite* sprite;

        //create sprite
        void createSprite(std::string file_image);
    public:
        //initialization
        EventView(int x, int y, std::string file_image, int width = CELL_SIDE, int height = CELL_SIDE);

        //get sprite
        sf::Sprite* getSprite();

        //destruction
        ~EventView();
};
