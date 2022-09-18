#include "Player.h"

//initialization
Player::Player(sf::String file_image, int pos_x, int pos_y, float width, float height){
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->width = width;
    this->height = height;
    this->file_image;
    image.loadFromFile("images/" + this->file_image);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(this->width, this->height, this->width, this->height));
};

//health
int Player::get_health(){
    return health;
};
void Player::set_health(int health){
    this->health = health;
};

//armor
int Player::get_armor(){
    return armor;
};
void Player::set_armor(int armor){
    this->armor = armor;
};

//mana
int Player::get_mana(){
    return mana;
};
void Player::set_mana(int mana){
    this->mana = mana;
};

//position x and y
float Player::get_position_x(){
    return pos_x;
};
float Player::get_position_y(){
    return pos_y;
};
void Player::set_position_x(float pos_x){
    this->pos_x = pos_x;
};
void Player::set_position_y(float pos_y){
    this->pos_y = pos_y;
};

//width and height
float Player::get_width(){
    return width;
};
float Player::get_height(){
    return height;
};

//speed
int Player::get_speed(){
    return speed;
};
void Player::set_speed(int speed){
    this->speed = speed;
};

//direction
int Player::get_direction(){
    return direction;
};
void Player::set_direction(int direction){
    this->direction = direction;
};

//update
void Player::update(float time){
    switch (direction){
        case 0:
            delta_x = speed;
            delta_y = 0;
            break;
        case 1:
            delta_x = -speed;
            delta_y = 0;
            break;
        case 2:
            delta_x = 0;
            delta_y = speed;
            break;
        case 3:
            delta_x = 0;
            delta_y = -speed;
            break;
    }
    pos_x += delta_x * time;
    pos_y += delta_y * time;

    speed = 0;
    sprite.setPosition(pos_x, pos_y);
};
