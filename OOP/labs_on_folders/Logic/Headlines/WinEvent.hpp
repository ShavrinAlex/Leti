#include "UnconditionalEvent.hpp"
#include "Game.hpp"

class WinEvent: public UnconditionalEvent{
    private:
        Game* game;
    public:
        //initialization
        WinEvent(Game* game);

        //execute
        void execute() override;
};
