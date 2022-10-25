#include "WinGameEvent.hpp"

//initialization
WinGameEvent::WinGameEvent(GameController* game_controller):EventOnGame(game_controller){};

//execute
EventStatus WinGameEvent::execute(){
    std::cout<<"You win!!!\n";
    game_controller->setGameStatus(Win);

    //logging
    Log* log = new Log(Processes, "Win game event was execute");
    this->mediator->send(log);
    delete log;

    return Delete;
};
