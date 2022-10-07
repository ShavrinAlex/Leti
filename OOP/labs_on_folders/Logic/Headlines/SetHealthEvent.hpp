#include "ConditionalEvent.hpp"
#include "Player.hpp"

class SetHealthEvent: public ConditionalEvent{
    private:
        int health;
        Player* player;

        //check conditional
        bool checkConditional() override;
    public:
        //initialization
        SetHealthEvent(Player* player, int health = 25);

        //execute
        void execute() override;
};
