#include "../Headlines/Player.hpp"

//initialization
Player::Player(int armor, int ammunition, int health, int speed, Direction direction):Entity(health, speed, direction){
    this->armor = armor;
    this->ammunition = ammunition;
};

//armor
int Player::getArmor(){
    return this->armor;
};
void Player::setArmor(int armor){
    this->armor = armor;
};

//ammunition
int Player::getAmmunition(){
    return this->ammunition;
};
void Player::setAmmunition(int ammunition){
    this->ammunition = ammunition;
};
