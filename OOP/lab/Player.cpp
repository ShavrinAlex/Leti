#include "Player.h"
#include <iostream>

//initialization
Player::Player(sf::String file_image, float width, float height){
    this->width = width;
    this->height = height;
    this->file_image;
    this->delta_x = 0.f;
    this->delta_y = 0.f;
    image.loadFromFile("images/hero/hero1.png"); //this->file_image
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(this->width, this->height, this->width, this->height));
};

//get draw object
sf::Sprite* Player::getDrawObject(){
    return &sprite;
};

 //set controller
 void Player::setController(Controller *controller){
    this->controller = controller;
 };

//move player
void Player::move(int direction){
    //std::cout<<"player move\n";
    controller->movePlayer(direction);
};

//health
int Player::getHealth(){
    return health;
};
void Player::setHealth(int health){
    this->health = health;
};

//armor
int Player::getArmor(){
    return armor;
};
void Player::setArmor(int armor){
    this->armor = armor;
};

//ammunition
int Player::getAmmunition(){
    return ammunition;
};
void Player::setAmmunition(int ammunition){
    this->ammunition = ammunition;
};

//width and height
float Player::getWidth(){
    return width;
};
float Player::getHeight(){
    return height;
};

//speed
int Player::getSpeed(){
    return speed;
};
void Player::setSpeed(float speed){
    this->speed = speed;
};

//direction
int Player::getDirection(){
    return direction;
};
void Player::setDirection(int direction){
    this->direction = direction;
};

//delta
int Player::getDeltaX(){
    return delta_x;
};
int Player::getDeltaY(){
    return delta_y;
};
void Player::setDeltaX(int delta_x){
    this->delta_x = delta_x;
};
void Player::setDeltaY(int delta_y){
    this->delta_y = delta_y;
};

//draw hero
void Player::draw(sf::RenderWindow *window){
    window->draw(sprite);
};

 /*
//update
void Player::update(float time, Map* M){
   
    //std::cout<<"update\n";
    switch (direction){
        case 0:
            //std::cout<<"case 0"<<'\n';
            delta_x = speed;
            //std::cout<<speed<<'\n';
            delta_y = 0;
            break;
        case 1:
            //std::cout<<"case 1"<<'\n';
            delta_x = -speed;
            delta_y = 0;
            break;
        case 2:
            //std::cout<<"case 2"<<'\n';
            delta_x = 0;
            delta_y = speed;
            break;
        case 3:
            //std::cout<<"case 3"<<'\n';
            delta_x = 0;
            delta_y = -speed;
            break;
    }
    float new_pos_x = pos_x + delta_x * time;
    float new_pos_y = pos_y + delta_y * time;

    if (check_ability_to_move(new_pos_x, new_pos_y, M)){
        pos_x += delta_x * time;
        pos_y += delta_y * time;
    }
    //std::cout<<"time = "<<time<<" dx = "<<delta_x<<" dy = "<<delta_y<<'\n';
    
    //std::cout<<pos_x<<' '<<pos_y<<'\n';

    speed = 0;
    sprite.setPosition(pos_x, pos_y);
   
};
 */

//position x and y
/*
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
*/
//check ability to move
/*
bool Player::check_ability_to_move(float new_pos_x, float new_pos_y, Map *M){
    bool ability = true;
    switch (direction){
        case 0:
            float right_x = new_pos_x + width;
            float lower_y = new_pos_y + height;
            float upper_y = new_pos_y;
            int ind_x = right_x / 98; //получаем индекс клетки по х в мап
            int ind_l_y = lower_y / 98; //получаем индекс клетки по y в мап
            int ind_u_y = upper_y / 98; //получаем индекс клетки по y в мап

            if ((M->get_map()->at(ind_l_y)->at(ind_x))->is_busy_cell()){
                ability = false;
            }
            if ((M->get_map()->at(ind_u_y)->at(ind_x))->is_busy_cell()){
                ability = false;
            }
            break;
        case 1:
            float left_x = new_pos_x;
            float lower_y = new_pos_y + height;
            float upper_y = new_pos_y;
            int ind_x = left_x / 98; //получаем индекс клетки по х в мап
            int ind_l_y = lower_y / 98; //получаем индекс клетки по y в мап
            int ind_u_y = upper_y / 98; //получаем индекс клетки по y в мап

            if ((M->get_map()->at(ind_l_y)->at(ind_x))->is_busy_cell()){
                ability = false;
            }
            if ((M->get_map()->at(ind_u_y)->at(ind_x))->is_busy_cell()){
                ability = false;
            }
            break;
        case 2:
            float left_x = new_pos_x;
            float right_x = new_pos_x + width;
            float lower_y = new_pos_y + height;
            int ind_r_x = right_x / 98; //получаем индекс клетки по х в мап
            int ind_l_x = left_x / 98; //получаем индекс клетки по х в мап
            int ind_y = lower_y / 98; //получаем индекс клетки по y в мап

            if ((M->get_map()->at(ind_y)->at(ind_r_x))->is_busy_cell()){
                ability = false;
            }
            if ((M->get_map()->at(ind_y)->at(ind_l_x))->is_busy_cell()){
                ability = false;
            }
            break;
        case 3:
            float left_x = new_pos_x;
            float right_x = new_pos_x + width;
            float upper_y = new_pos_y;
            int ind_r_x = right_x / 98; //получаем индекс клетки по х в мап
            int ind_l_x = left_x / 98; //получаем индекс клетки по х в мап
            int ind_y = upper_y / 98; //получаем индекс клетки по y в мап

            if ((M->get_map()->at(ind_y)->at(ind_r_x))->is_busy_cell()){
                ability = false;
            }
            if ((M->get_map()->at(ind_y)->at(ind_l_x))->is_busy_cell()){
                ability = false;
            }
            break;
    }
    return ability;
};
*/