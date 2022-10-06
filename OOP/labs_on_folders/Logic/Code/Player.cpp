#include "../Headlines/Player.hpp"

//initialization
Player::Player(bool armor, int ammunition, int health, int speed, Direction direction):Entity(health, speed, direction){
    this->armor = armor;
    this->ammunition = ammunition;
};

//armor
bool Player::getArmor(){
    return this->armor;
};
void Player::setArmor(bool armor){
    this->armor = armor;

    //notify observer
    this->notify();
};

//ammunition
int Player::getAmmunition(){
    return this->ammunition;
};
void Player::setAmmunition(int ammunition){
    this->ammunition = ammunition;
    
    //notify observer
    this->notify();
};
