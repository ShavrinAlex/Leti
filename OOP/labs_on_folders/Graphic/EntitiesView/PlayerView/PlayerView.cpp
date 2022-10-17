#include "PlayerView.hpp"
#define SCALE_HEIGHT 5

//initialization
PlayerView::PlayerView(Player* player, int width, int height, Position* pos, std::string file_image):EntityView(player, width, height, pos, file_image){
    //create armor scale
    createArmorScale();

    //create energy scale
    createEnergyScale();

    //update energy and armor scale position and size
    this->updateEnergyScale();
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

//create energy scale
void PlayerView::createEnergyScale(){
    //create energy scale stroke
    this->energy_scale_stroke = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->energy_scale_stroke->setOutlineThickness(-1);
    this->energy_scale_stroke->setOutlineColor(sf::Color(0, 0, 139));
    this->energy_scale_stroke->setFillColor(sf::Color(45, 200, 255, 0));

    //create energy scale
    this->energy_scale = new sf::RectangleShape(sf::Vector2f(this->width - 10, SCALE_HEIGHT));
    this->energy_scale->setFillColor(sf::Color(45, 200, 255));
};

//update energy scale
void PlayerView::updateEnergyScale(){
    //energy scale size
    this->energy_scale->setSize(sf::Vector2f((this->width - 10) * (((Player*)entity)->getEnergy()/100.0), SCALE_HEIGHT));
    this->energy_scale_stroke->setSize(sf::Vector2f((this->width - 10) * bool(((Player*)entity)->getEnergy()), SCALE_HEIGHT * bool(((Player*)entity)->getEnergy())));

    //energy scale position
    this->energy_scale->setPosition(position.x * this->width + 5, ((position.y + 1) * this->height) - SCALE_HEIGHT);
    this->energy_scale_stroke->setPosition(position.x * this->width + 5, ((position.y + 1) * this->height) - SCALE_HEIGHT);
};

//update armor scale position and size
void PlayerView::updateArmorScale(){
    //armor scale size
    this->armor_scale->setSize(sf::Vector2f((this->width - 10) * (((Player*)entity)->getArmor()), SCALE_HEIGHT));
    this->armor_scale_stroke->setSize(sf::Vector2f((this->width - 10) * (((Player*)entity)->getArmor()), SCALE_HEIGHT * (((Player*)entity)->getArmor())));

    //armor scale position
    this->armor_scale->setPosition(position.x * this->width + 5, (position.y * this->height) + SCALE_HEIGHT);
    this->armor_scale_stroke->setPosition(position.x * this->width + 5, (position.y * this->height) + SCALE_HEIGHT);
};

//get energy scale
sf::RectangleShape* PlayerView::getEnergyScale(){
    return this->energy_scale;
};

//get energy scale stroke
sf::RectangleShape* PlayerView::getEnergyScaleStroke(){
    return this->energy_scale_stroke;
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
    this->updateEnergyScale();
    this->updateArmorScale();
};

//destruction
PlayerView::~PlayerView(){
    delete energy_scale;
    delete energy_scale_stroke;
    delete armor_scale;
    delete armor_scale_stroke;
};
