#pragma once
#include "../../Utility/Enumerations.hpp"
#include "../../ObserverPattern/Observable/Observable.hpp"
#include "../../Logging/Log/Log.hpp"
#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"

class Entity: public Observable{
    protected:
        int health;
        int speed;
        int damage;
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

        //damage
        int getDamage();
        void setDamage(int damage);

        //direction
        Direction getDirection();
        void setDirection(Direction direction);
};
