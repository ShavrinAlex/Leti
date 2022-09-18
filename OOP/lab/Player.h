#include <SFML/Graphics.hpp>

class Player{
    private:
        int health, armor, mana;
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

        //mana
        int get_mana();
        void set_mana(int mana);

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
        void set_speed(int speed);

        //direction
        int get_direction();
        void set_direction(int direction);

        //update
        void update(float time);
        
        //destructor
        ~Player(){};
};
