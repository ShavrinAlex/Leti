#include "Entity.hpp"
#define MIN_DAMAGE 25

//initialization
Entity::Entity(int health, int speed, Direction direction){
    this->health = health;
    this->speed = speed;
    this->damage = MIN_DAMAGE;
    this->direction = direction;
};

//health
int Entity::getHealth(){
    return this->health;
};
void Entity::setHealth(int health){
    this->health = health;
    
    //notify observers
    this->notify();
};

//speed
int Entity::getSpeed(){
    return this->speed;
};
void Entity::setSpeed(float speed){
    this->speed = speed;
};

//damage
int Entity::getDamage(){
    return this->damage;
};
void Entity::setDamage(int damage){
    this->damage = damage;
};

//direction
Direction Entity::getDirection(){
    return this->direction;
};
void Entity::setDirection(Direction direction){
    this->direction = direction;

    //notify observer
    this->notify();
};
