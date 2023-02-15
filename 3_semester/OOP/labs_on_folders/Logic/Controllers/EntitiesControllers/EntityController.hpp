#pragma once
#include "../../Entities/Entity/Entity.hpp"
#include "../../Logging/Log/Log.hpp"
#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"

class EntityController: public GameElement<Log*>{
    public:
        //take damage
        virtual void takeDamage(int damage, Entity* entity) = 0;

        //destruction
        virtual ~EntityController(){};
};
