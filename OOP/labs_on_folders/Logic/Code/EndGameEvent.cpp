#include "../Headlines/EndGameEvent.hpp"

//initialization
EndGameEvent::EndGameEvent(Game* game):EventOnGame(game){};

//execute
EventStatus EndGameEvent::execute(){
    std::cout<<"You loose!!!\n";
    game->setGameStatus(LOOSE);
    return DELETE;
};
