#include "EventOnGame.hpp"

class EndGameEvent: public EventOnGame{
    public:
        //initialization
        EndGameEvent(Game* game);

        //execute
        EventStatus execute() override;
};
