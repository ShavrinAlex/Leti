#include "../EventOnPlayer/EventOnPlayer.hpp"

class SetHealthEvent: public EventOnPlayer{
    private:
        int health;

        //check conditional
        bool checkConditional() override;
    public:
        //initialization
        SetHealthEvent(Player* player, int health = 25);

        //execute
        EventStatus execute() override;
};
