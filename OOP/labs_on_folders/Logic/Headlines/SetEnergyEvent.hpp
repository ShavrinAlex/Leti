#include "EventOnPlayer.hpp"

class SetEnergyEvent: public EventOnPlayer{
    private:
        int energy;

        //check conditional
        bool checkConditional() override;
    public:
        //initialization
        SetEnergyEvent(Player* player, int energy = 25);

        //execute
        EventStatus execute() override;
};