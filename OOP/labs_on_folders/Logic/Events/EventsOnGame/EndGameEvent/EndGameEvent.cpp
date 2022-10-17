#include "EndGameEvent.hpp"

//initialization
EndGameEvent::EndGameEvent(GameController* game_controller):EventOnGame(game_controller){};

//execute
EventStatus EndGameEvent::execute(){
    std::cout<<"You loose!!!\n";
    game_controller->setGameStatus(Loose);
    return Delete;
};
