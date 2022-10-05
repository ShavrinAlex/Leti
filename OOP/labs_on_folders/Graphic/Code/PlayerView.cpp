#include "../Headlines/PlayerView.hpp"
#define SCALE_HEIGHT 5

//initialization
PlayerView::PlayerView(Player* player, int width, int height, Position* pos, std::string file_image):EntityView(player, width, height, pos, file_image){
    //set observer
    this->entity->setObserver(this);

    //scale stroke
    this->ammunition_scale_stroke = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->ammunition_scale_stroke->setOutlineThickness(-1);
    this->ammunition_scale_stroke->setOutlineColor(sf::Color(0, 0, 139));

    //ammunition scale
    this->ammunition_scale = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->ammunition_scale->setFillColor(sf::Color(45, 200, 255));
    
    //update ammunition scale position and size
    updateAmmunitionScale();
};

//update ammunition scale
void PlayerView::updateAmmunitionScale(){
    //ammunition scale position
    this->ammunition_scale->setPosition(position.x * this->width + 5, (position.y * this->height) + SCALE_HEIGHT);
    this->ammunition_scale_stroke->setPosition(position.x * this->width + 5, (position.y * this->height) + SCALE_HEIGHT);
};

//get ammunition scale
sf::RectangleShape* PlayerView::getAmmunitionScale(){
    return this->ammunition_scale;
};

//get scale stroke
sf::RectangleShape* PlayerView::getAmmunitionScaleStroke(){
    return this->ammunition_scale_stroke;
};

//update
void PlayerView::update(){
    EntityView::update();
    this->updateAmmunitionScale();
};
