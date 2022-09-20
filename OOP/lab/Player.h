#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"


class Player{
    private:
        int health, armor, ammunition;
        float pos_x, pos_y, width, height, delta_x, delta_y, speed;
        int direction;
        sf::String file_image;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        //initialization
        Player(sf::String file_image, int pos_x, int pos_y, float width, float height);
        
        //health
        int get_health();
        void set_health(int health);

        //armor
        int get_armor();
        void set_armor(int armor);

        //ammunition
        int get_ammunition();
        void set_ammunition(int ammunition);

        //position x and y
        float get_position_x();
        float get_position_y();
        void set_position_x(float pos_x);
        void set_position_y(float pos_y);

        //width and height
        float get_width();
        float get_height();
        
        //speed
        int get_speed();
        void set_speed(float speed);

        //direction
        int get_direction();
        void set_direction(int direction);

        //check ability to move
        bool check_ability_to_move(float new_pos_x, float new_pos_y, Map *M);

        //update
        void update(float time, Map *M);

        //draw hero
        void draw(sf::RenderWindow *window);
        
        //destructor
        ~Player(){};
};
