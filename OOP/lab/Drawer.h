#pragma once
#include <SFML/Graphics.hpp>
#include "Controller.h"

class Drawer{
    private:
        Controller* controller;
    public:
        //set controller
        void setController(Controller* controller);

        //draw map
        void drawMap(sf::RenderWindow* window);

        //draw player
        void drawPlayer(sf::RenderWindow* window);
};
