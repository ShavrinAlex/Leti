#include "../Headlines/PlayerView.hpp"
#define SCALE_HEIGHT 5

//initialization
PlayerView::PlayerView(Player* player, int width, int height, Position* pos, std::string file_image):EntityView(player, width, height, pos, file_image){
    //set observer
    this->entity->setObserver(this);

    //create armor scale
    createArmorScale();

    //create ammunition scale
    createAmmunitionScale();

    //update ammunition and armor scale position and size
    this->updateAmmunitionScale();
    this->updateArmorScale();
};

//create armor scale
void PlayerView::createArmorScale(){
    //create armor scale stroke
    this->armor_scale_stroke = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->armor_scale_stroke->setOutlineThickness(-1);
    this->armor_scale_stroke->setOutlineColor(sf::Color(128, 128, 128));
    this->armor_scale_stroke->setFillColor(sf::Color(192, 192, 192, 0));

    //create armor scale
    this->armor_scale = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->armor_scale->setFillColor(sf::Color(192, 192, 192));
};

//create ammunition scale
void PlayerView::createAmmunitionScale(){
    //create ammunition scale stroke
    this->ammunition_scale_stroke = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->ammunition_scale_stroke->setOutlineThickness(-1);
    this->ammunition_scale_stroke->setOutlineColor(sf::Color(0, 0, 139));
    this->ammunition_scale_stroke->setFillColor(sf::Color(45, 200, 255, 0));

    //create ammunition scale
    this->ammunition_scale = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->ammunition_scale->setFillColor(sf::Color(45, 200, 255));
};

//update ammunition scale
void PlayerView::updateAmmunitionScale(){
    //ammunition scale size
    this->ammunition_scale->setSize(sf::Vector2f((this->width - 10)*(((Player*)entity)->getAmmunition()/100.0), SCALE_HEIGHT));

    //ammunition scale position
    this->ammunition_scale->setPosition(position.x * this->width + 5, ((position.y + 1) * this->height) - SCALE_HEIGHT);
    this->ammunition_scale_stroke->setPosition(position.x * this->width + 5, ((position.y + 1) * this->height) - SCALE_HEIGHT);
};

//update armor scale position and size
void PlayerView::updateArmorScale(){
    //armor scale size
    this->armor_scale->setSize(sf::Vector2f((this->width - 10)*(((Player*)entity)->getArmor()), SCALE_HEIGHT));

    //armor scale position
    this->armor_scale->setPosition(position.x * this->width + 5, (position.y * this->height) + SCALE_HEIGHT);
    this->armor_scale_stroke->setPosition(position.x * this->width + 5, (position.y * this->height) + SCALE_HEIGHT);
};

//get ammunition scale
sf::RectangleShape* PlayerView::getAmmunitionScale(){
    return this->ammunition_scale;
};

//get ammunition scale stroke
sf::RectangleShape* PlayerView::getAmmunitionScaleStroke(){
    return this->ammunition_scale_stroke;
};

//get armor scale
sf::RectangleShape* PlayerView::getArmorScale(){
    return this->armor_scale;
};

//get armor scale stroke
sf::RectangleShape* PlayerView::getArmorScaleStroke(){
    return this->armor_scale_stroke;
};

//update
void PlayerView::update(){
    EntityView::update();
    this->updateAmmunitionScale();
    this->updateArmorScale();
};
