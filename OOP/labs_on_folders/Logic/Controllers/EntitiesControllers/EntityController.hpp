#pragma once
#include "../../Entities/Entity/Entity.hpp"

class EntityController{
    public:
        //take damage
        virtual void takeDamage(int damage, Entity* entity) = 0;

        //destruction
        virtual ~EntityController(){};
};
