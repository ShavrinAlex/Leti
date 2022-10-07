#include "../Headlines/Player.hpp"

//initialization
Player::Player(bool armor, int energy, int health, int speed, Direction direction):Entity(health, speed, direction){
    this->armor = armor;
    this->energy = energy;
};

//armor
bool Player::getArmor(){
    return this->armor;
};
void Player::setArmor(){
    this->armor = true;

    //notify observer
    this->notify();
};
void Player::removeArmor(){
    this->armor = false;

    //notify observer
    this->notify();
};

//energy
int Player::getEnergy(){
    return this->energy;
};
void Player::setEnergy(int energy){
    this->energy = energy;
    
    //notify observer
    this->notify();
};
