#include "../EventOnPlayer/EventOnPlayer.hpp"

class SetArmorEvent: public EventOnPlayer{
    private:
        //check conditional
        bool checkConditional() override;
    public:
        //initialization
        SetArmorEvent(Player* player);

        //execute
        EventStatus execute() override;
};
