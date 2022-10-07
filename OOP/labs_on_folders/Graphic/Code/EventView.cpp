#include "../Headlines/EventView.hpp"

//initialization
EventView::EventView(int x, int y, std::string file_image, int width, int height){
    //sprite size
    this->width = width;
    this->height = height;

    //position
    this->position.x = x * this->width;
    this->position.y = y * this->height;

    //create sprite
    createSprite(file_image);
};

//create sprite
void EventView::createSprite(std::string file_image){
    this->file_image = file_image;
    this->image.loadFromFile(this->file_image); 
    this->texture.loadFromImage(image);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(texture);
    this->sprite->setTextureRect(sf::IntRect(0, 0, this->width, this->height));
    this->sprite->setPosition(sf::Vector2f(this->position.x, this->position.y));
};

//get sprite
sf::Sprite* EventView::getSprite(){
    return this->sprite;
};

//destruction
EventView::~EventView(){
    delete this->sprite;
};