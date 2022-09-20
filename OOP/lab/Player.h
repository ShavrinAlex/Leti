#pragma once
#include "SFML/Graphics.hpp"
#include "Controller.h"

class Player{
    private:
        int health, armor, ammunition;
        float width, height, delta_x, delta_y, speed;
        int direction;
        sf::String file_image;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;
        Controller* controller;

    public:
        //initialization
        Player(sf::String file_image, float width, float height);
        
        //set controller
        void setController(Controller *controller);

        //get draw object
        sf::Sprite* getDrawObject();

        //move player
        void move(int direction);

        //health
        int getHealth();
        void setHealth(int health);

        //armor
        int getArmor();
        void setArmor(int armor);

        //ammunition
        int getAmmunition();
        void setAmmunition(int ammunition);

        //position x and y
        /*
        float get_position_x();
        float get_position_y();
        void set_position_x(float pos_x);
        void set_position_y(float pos_y);
        */

        //width and height
        float getWidth();
        float getHeight();
        
        //speed
        int getSpeed();
        void setSpeed(float speed);

        //direction
        int getDirection();
        void setDirection(int direction);

        //delta
        int getDeltaX();
        int getDeltaY();
        void setDeltaX(int delta_x);
        void setDeltaY(int delta_y);

        void draw(sf::RenderWindow *window);
        /*
        //update
        void update(float time, Map *M);

        //draw hero
        void draw(sf::RenderWindow *window);
        */
        //destructor
        ~Player(){};
};
