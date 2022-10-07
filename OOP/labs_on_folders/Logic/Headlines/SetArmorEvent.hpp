#include "ConditionalEvent.hpp"
#include "Player.hpp"

class SetArmorEvent: public ConditionalEvent{
    private:
        Player* player;

        //check conditional
        bool checkConditional() override;
    public:
        //initialization
        SetArmorEvent(Player* player);

        //execute
        void execute() override;
};
