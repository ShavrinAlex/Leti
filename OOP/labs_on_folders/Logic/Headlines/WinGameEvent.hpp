#include "EventOnGame.hpp"

class WinGameEvent: public EventOnGame{
    public:
        //initialization
        WinGameEvent(Game* game);

        //execute
        EventStatus execute() override;
};
