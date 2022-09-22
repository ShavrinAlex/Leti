#include "Entity.h"

//initialization
Entity::Entity(int health = 100, int speed = 0, std::string direction = "Not"){
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
std::string Entity::getDirection(){
    return direction;
};
void Entity::setDirection(std::string direction){
    this->direction = direction;
};
