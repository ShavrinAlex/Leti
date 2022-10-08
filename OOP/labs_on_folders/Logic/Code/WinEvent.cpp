#include "../Headlines/WinEvent.hpp"
#include "../Headlines/Enumerations.hpp"

//initialization
WinEvent::WinEvent(Game* game){
    this->game = game;
};

//execute
void WinEvent::execute(){
    std::cout<<"You win!!!\n";
    game->setGameStatus(WIN);
};
