#include "EntityView.hpp"

//initialization
EntityView::EntityView(Entity* entity, int width, int height, std::string file_image){
    this->entity = entity;
    this->width = width;
    this->height = height;
    this->file_image = file_image;
    this->image.loadFromFile("images/entities/" + this->file_image);
    this->texture.loadFromImage(image);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(texture);
    this->sprite->setTextureRect(sf::IntRect(this->width, this->height, this->width, this->height));
};

//set position
void EntityView::setPosition(Position *player_position){
    this->sprite->setPosition(player_position->x * this->width, player_position->y * this->height);
};

//update sprite
void EntityView::updateSprite(){
    //std::cout<<entity.getDirection()<<'\n';
    switch (entity->getDirection()){
        case Right:
            //set texture rect
            this->sprite->setTextureRect(sf::IntRect(this->width-5, this->height*2, this->width, this->height));
            break;
        case Left:
            //set texture rect
            this->sprite->setTextureRect(sf::IntRect(this->width, this->height, this->width, this->height));
            break;
        case Up:
            //set texture rect
            this->sprite->setTextureRect(sf::IntRect(this->width, this->height*3, this->width, this->height));
            break;
        case Down:
            //set texture rect
            this->sprite->setTextureRect(sf::IntRect(this->width, this->height*0, this->width, this->height));
            break;
    }
}

//get draw object
sf::Sprite* EntityView::getDrawObject(){
    updateSprite();
    return sprite;
};
