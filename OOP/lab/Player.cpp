#include "Player.h"
#include <iostream>

//initialization
Player::Player(sf::String file_image, int pos_x, int pos_y, float width, float height){
    this->pos_x = pos_x;
    this->pos_y = pos_y;
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

//ammunition
int Player::get_ammunition(){
    return ammunition;
};
void Player::set_ammunition(int ammunition){
    this->ammunition = ammunition;
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
void Player::set_speed(float speed){
    this->speed = speed;
};

//direction
int Player::get_direction(){
    return direction;
};
void Player::set_direction(int direction){
    this->direction = direction;
};

//draw hero
void Player::draw(sf::RenderWindow *window){
    window->draw(sprite);
};

//check ability to move
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
