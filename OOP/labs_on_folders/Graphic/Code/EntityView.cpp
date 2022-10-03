#include "../Headlines/EntityView.hpp"
#define SCALE_HEIGHT 5

//initialization
EntityView::EntityView(Entity* entity, int width, int height, Position* pos, std::string file_image){
    //logic entity
    this->entity = entity;

    //sprite size
    this->width = width;
    this->height = height;

    //position
    this->position.x = pos->x * this->width;
    this->position.y = pos->y * this->height;

    //sprite initialization
    this->file_image = file_image;
    this->image.loadFromFile(this->file_image); 
    this->texture.loadFromImage(image);
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(texture);
    this->sprite->setTextureRect(sf::IntRect(this->width, this->height, this->width, this->height));

    //health scale stroke
    this->health_scale_stroke = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->health_scale_stroke->setOutlineThickness(-1);
    this->health_scale_stroke->setOutlineColor(sf::Color(139, 0, 0));
    
    //health scale
    this->health_scale = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->health_scale->setFillColor(sf::Color(255, 0, 0));

    //update heakth scale position and size
    updateHealthScale();

    //update sprite direction
    updateSprite();
};

//set position
void EntityView::setPosition(Position *player_position){
    //set new position
    position.x = player_position->x;
    position.y = player_position->y; 

    //update heakth scale position and size
    updateHealthScale();

    //update sprite direction
    updateSprite();
};

//update sprite
void EntityView::updateSprite(){
    //update sprite position
    this->sprite->setPosition(position.x * this->width, position.y * this->height);

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
        case Stay:
            //set texture rect
            this->sprite->setTextureRect(sf::IntRect(this->width, this->height*0, this->width, this->height));
            break;
    }
};

//update health scale
void EntityView::updateHealthScale(){
    //health scale position
    this->health_scale->setPosition(position.x * this->width + 5, position.y * this->height);
    this->health_scale_stroke->setPosition(position.x * this->width + 5, position.y * this->height);
};

//get sprite
sf::Sprite* EntityView::getSprite(){
    updateSprite();
    return this->sprite;
};

//get health scale
sf::RectangleShape* EntityView::getHealthScale(){
    updateHealthScale();
    return this->health_scale;
};

//get health scale
sf::RectangleShape* EntityView::getHealthScaleStroke(){
    updateHealthScale();
    return this->health_scale_stroke;
};

//destruction
EntityView::~EntityView(){
    delete sprite;
};
