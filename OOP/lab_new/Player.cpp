#include "Player.h"

//initialization
Player::Player(int armor = 0, int ammunition = 0, int health = 100, int speed = 0, std::string direction = "Not"){
    this->armor = armor;
    this->ammunition = ammunition;
    //Entity::Entity(int health, int speed, std::string direction);
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
