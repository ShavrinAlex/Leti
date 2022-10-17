#include "WinGameEvent.hpp"

//initialization
WinGameEvent::WinGameEvent(GameController* game_controller):EventOnGame(game_controller){};

//execute
EventStatus WinGameEvent::execute(){
    std::cout<<"You win!!!\n";
    game_controller->setGameStatus(Win);
    return Delete;
};
