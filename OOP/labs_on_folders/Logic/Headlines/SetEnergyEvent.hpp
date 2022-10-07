#include "ConditionalEvent.hpp"
#include "Player.hpp"

class SetEnergyEvent: public ConditionalEvent{
    private:
        int energy;
        Player* player;

        //check conditional
        bool checkConditional() override;
    public:
        //initialization
        SetEnergyEvent(Player* player, int energy = 25);

        //execute
        void execute() override;
};