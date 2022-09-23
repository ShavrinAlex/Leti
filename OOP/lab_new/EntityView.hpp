#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <string>

class EntityView{
    private:
        int width;
        int height;
        Entity entity;
        std::string file_image;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite* sprite;

        //update sprite
        void updateSprite();
        
    public:
        //initialization
        EntityView(Entity& entity, int width, int height, std::string file_image);

        //get draw object
        sf::Sprite* getDrawObject();
};
