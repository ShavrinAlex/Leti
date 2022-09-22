#include "Entity.h"
#include <string>

class Player: public Entity{
    private:
        int armor;
        int ammunition;
    public:
        //initialization
        Player(int armor = 0, int ammunition = 0, int health = 100, int speed = 0, std::string direction = "Not");

        //armor
        int getArmor();
        void setArmor(int armor);

        //ammunition
        int getAmmunition();
        void setAmmunition(int ammunition);
};
