#include "Player.hpp"

//initialization
Player::Player(int armor = 0, int ammunition = 0, int health = 100, int speed = 0, Direction direction = Right):Entity(health, speed, direction){
    this->armor = armor;
    this->ammunition = ammunition;
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
