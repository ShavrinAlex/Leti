#include "../Headlines/Entity.hpp"

//initialization
Entity::Entity(int health, int speed, Direction direction){
    this->health = health;
    this->speed = speed;
    this->direction = direction;
};

//health
int Entity::getHealth(){
    return this->health;
};
void Entity::setHealth(int health){
    this->health = health;
};

//speed
int Entity::getSpeed(){
    return this->speed;
};
void Entity::setSpeed(float speed){
    this->speed = speed;
};

//direction
Direction Entity::getDirection(){
    return this->direction;
};
void Entity::setDirection(Direction direction){
    this->direction = direction;
};
