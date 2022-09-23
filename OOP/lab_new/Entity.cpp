#include "Entity.hpp"

//initialization
Entity::Entity(int health = 100, int speed = 0, Direction direction = Right){
    this->health = health;
    this->speed = speed;
    this->direction = direction;
};

//health
int Entity::getHealth(){
    return health;
};
void Entity::setHealth(int health){
    this->health = health;
};

//speed
int Entity::getSpeed(){
    return speed;
};
void Entity::setSpeed(float speed){
    this->speed = speed;
};

//direction
Direction Entity::getDirection(){
    return direction;
};
void Entity::setDirection(Direction direction){
    this->direction = direction;
};
