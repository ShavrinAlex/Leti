#pragma once
#include <SFML/Graphics.hpp>

class Cell{
    private:
        float side;
        sf::Color color;
        bool is_busy, hero_is_here;
        sf::RectangleShape* cell;
    public:
        //initialization
        Cell(float side, bool is_busy, bool hero_is_here);
        /*
        void draw(sf::RenderWindow *window);
        */
        //create cell
        sf::RectangleShape* create_cell();

        //get cell obj for draw
        sf::RectangleShape* getDrawObject();

        //side
        float getSide();
        
        //check is busy cell
        bool is_busy_cell();

        //set hero
        void setHero(bool is_here);

        //reaction on hero
        void reaction_on_hero();

        //update
        void update();

        //destructor
        ~Cell(){};

        //draw cell
        //void draw(sf::RenderWindow *window);

        //position x and y
        //float get_position_x();
        //float get_position_y();
        //void set_position_x(float pos_x);
        //void set_position_y(float pos_y);
};
