#include "../EventOnGame/EventOnGame.hpp"

class EndGameEvent: public EventOnGame{
    public:
        //initialization
        EndGameEvent(GameController* game_controller);

        //execute
        EventStatus execute() override;
};
