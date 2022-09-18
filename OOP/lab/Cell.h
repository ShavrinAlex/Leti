#include <SFML/Graphics.hpp>
#include "Player.h"

class Cell{
    private:
        float pos_x, pos_y, side;
        sf::Color color;
        bool is_bussy;
        sf::RectangleShape *cell;
    public:
        //initialization
        Cell(int num_x, int num_y, float side, bool is_bussy);

        //create cell
        sf::RectangleShape* create_cell();

        //draw cell
        void draw(sf::RenderWindow *window);

        //position x and y
        //float get_position_x();
        //float get_position_y();
        void set_position_x(float pos_x);
        void set_position_y(float pos_y);

        //side
        float get_side();
        /*
        //check hero is here
        bool hero_is_here(Player *hero);
        
        //check is busy cell
        bool is_busy_cell();

        //reaction on hero
        void reaction_on_hero(Player *hero);
        */
        //destructor
        ~Cell(){};
};
