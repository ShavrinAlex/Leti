#pragma once
#include "Entity.hpp"
#include <string>

class Player: public Entity{
    private:
        bool armor;
        int ammunition;
    public:
        //initialization
        Player(bool armor = true, int ammunition = 0, int health = 70, int speed = 0, Direction direction = Right);

        //armor
        bool getArmor();
        void setArmor(bool armor);

        //ammunition
        int getAmmunition();
        void setAmmunition(int ammunition);
};
