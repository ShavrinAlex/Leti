#include "../Headlines/WinGameEvent.hpp"

//initialization
WinGameEvent::WinGameEvent(Game* game):EventOnGame(game){};

//execute
EventStatus WinGameEvent::execute(){
    std::cout<<"You are winner!!!\n";
    game->setGameStatus(WIN);
    return DELETE;
};
