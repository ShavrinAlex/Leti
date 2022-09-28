#pragma once
#include "Entity.hpp"
#include "GameElement.hpp"
#include <string>

class Player: public Entity, public GameElement{
    private:
        int armor;
        int ammunition;
    public:
        //initialization
        Player(int armor = 0, int ammunition = 0, int health = 100, int speed = 0, Direction direction = Right);

        //armor
        int getArmor();
        void setArmor(int armor);

        //ammunition
        int getAmmunition();
        void setAmmunition(int ammunition);
};
