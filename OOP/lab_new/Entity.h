#include <string>

class Entity{
    protected:
        int health;
        int speed;
        std::string direction;
    public:
        //initialization
        Entity(int health = 100, int speed = 0, std::string direction = "Not");

        //health
        int getHealth();
        void setHealth(int health);

        //speed
        int getSpeed();
        void setSpeed(float speed);

        //direction
        std::string getDirection();
        void setDirection(std::string direction);
};
