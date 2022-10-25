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

    //notifi loger
    //this->mediator->send(new Log(Processes, "entity's health changed"));
};

//speed
int Entity::getSpeed(){
    return this->speed;
};
void Entity::setSpeed(float speed){
    this->speed = speed;

    //notifi loger
    //this->mediator->send(new Log(Processes, "entity's speed changed"));
};

//damage
int Entity::getDamage(){
    return this->damage;
};
void Entity::setDamage(int damage){
    this->damage = damage;

    //notifi loger
    //this->mediator->send(new Log(Processes, "entity's damage value changed"));
};

//direction
Direction Entity::getDirection(){
    return this->direction;
};
void Entity::setDirection(Direction direction){
    this->direction = direction;

    //notify observer
    this->notify();

    //notifi loger
    //std::string message = "entity's direction changed";
    //this->mediator->send(new Log(Processes, message));
};
