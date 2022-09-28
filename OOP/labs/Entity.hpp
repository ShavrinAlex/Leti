#pragma once
#include <string>
#include "Enumerations.hpp"

class Entity{
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
