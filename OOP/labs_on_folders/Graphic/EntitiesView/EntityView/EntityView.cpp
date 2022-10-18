#include "EntityView.hpp"
#define SCALE_HEIGHT 5
#include <iostream>
//initialization
EntityView::EntityView(Entity* entity, int width, int height, Position* pos, std::string file_image){
    //logic entity
    this->entity = entity;
    this->entity->addObserver(this);

    //sprite size
    this->width = width;
    this->height = height;

    //position
    this->position.x = pos->x * this->width;
    this->position.y = pos->y * this->height;

    //create sprite
    createSprite(file_image);
    
    //create health scale
    this->createHealthScale();

    //update heakth scale position and size
    updateHealthScale();

    //update sprite direction
    updateSprite();
};

//set position
void EntityView::setPosition(Position *entity_position){
    //set new position
    this->position.x = entity_position->x * this->width;
    this->position.y = entity_position->y * this->height;

    //update
    this->update();
};

//create sprite
void EntityView::createSprite(std::string file_image){
    this->file_image = file_image;
    this->image.loadFromFile(this->file_image); 
    this->texture.loadFromImage(image);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(texture);
    this->sprite->setTextureRect(sf::IntRect(this->width, this->height, this->width, this->height));
};

//create health scale
void EntityView::createHealthScale(){
    //create health scale stroke
    this->health_scale_stroke = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->health_scale_stroke->setOutlineThickness(-1);
    this->health_scale_stroke->setOutlineColor(sf::Color(139, 0, 0));
    this->health_scale_stroke->setFillColor(sf::Color(255, 0, 0, 0));
    
    //create health scale
    this->health_scale = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->health_scale->setFillColor(sf::Color(255, 0, 0));
};

//update sprite
void EntityView::updateSprite(){
    //update sprite position
    this->sprite->setPosition(position.x, position.y);

    //update sprite direction
    switch (this->entity->getDirection()){
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
};

//update health scale
void EntityView::updateHealthScale(){
    //health scale size
    this->health_scale->setSize(sf::Vector2f((this->width - 10)*(this->entity->getHealth()/100.0), SCALE_HEIGHT));

    //health scale position
    this->health_scale->setPosition(position.x + 5, position.y);
    this->health_scale_stroke->setPosition(position.x + 5, position.y);
};

//get sprite
sf::Sprite* EntityView::getSprite(){
    return this->sprite;
};

//get health scale
sf::RectangleShape* EntityView::getHealthScale(){
    return this->health_scale;
};

//get health scale
sf::RectangleShape* EntityView::getHealthScaleStroke(){
    return this->health_scale_stroke;
};

//update
void EntityView::update(){
    this->updateSprite();
    this->updateHealthScale();
};

//destruction
EntityView::~EntityView(){
    this->entity = nullptr;
    delete sprite;
    delete health_scale;
    delete health_scale_stroke;
};
