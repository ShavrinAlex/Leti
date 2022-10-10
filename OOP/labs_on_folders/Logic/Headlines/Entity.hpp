#pragma once
#include <string>
#include "Enumerations.hpp"
#include "GameElement.hpp"
#include "Observable.hpp"

class Entity: public GameElement, public Observable{
    protected:
        int health;
        int speed;
        Direction direction;
    public:
        //initialization
        Entity(int health = 100, int speed = 0, Direction direction = Right);

        //health
        int getHealth();
        void setHealth(int health);

        //speed
        int getSpeed();
        void setSpeed(float speed);

        //direction
        Direction getDirection();
        void setDirection(Direction direction);
};
