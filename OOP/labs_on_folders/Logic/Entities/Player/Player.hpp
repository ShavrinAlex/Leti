#pragma once
#include "../Entity/Entity.hpp"


class Player: public Entity{
    private:
        bool armor;
        int energy;
    public:
        //initialization
        Player(bool armor = false, int energy = 50, int health = 75, int speed = 0, Direction direction = Right);

        //armor
        bool getArmor();
        void setArmor();
        void removeArmor();

        //energy
        int getEnergy();
        void setEnergy(int energy);
};
