#pragma once
#include "Entity.hpp"
#include <string>

class Player: public Entity{
    private:
        bool armor;
        int energy;
    public:
        //initialization
        Player(bool armor = false, int energy = 0, int health = 100, int speed = 0, Direction direction = Right);

        //armor
        bool getArmor();
        void setArmor();
        void removeArmor();

        //energy
        int getEnergy();
        void setEnergy(int energy);
};
