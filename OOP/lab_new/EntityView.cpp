#include "EntityView.hpp"

//initialization
EntityView::EntityView(Entity& entity, int width, int height, std::string file_image){
    this->entity = entity;
    this->width = width;
    this->height = height;
    this->file_image = file_image;
    image.loadFromFile("images/entities/" + this->file_image);
    texture.loadFromImage(image);
    sprite->setTexture(texture);
    sprite->setTextureRect(sf::IntRect(this->width, this->height, this->width, this->height));
};

//update sprite
void EntityView::updateSprite(){
    switch (entity.getDirection()){
        case Right:
            //set texture rect
            break;
        case Left:
            //set texture rect
            break;
        case Up:
            //set texture rect
            break;
        case Down:
            //set texture rect
            break;
    }
}

//get draw object
sf::Sprite* EntityView::getDrawObject(){
    updateSprite();
    return sprite;
};
