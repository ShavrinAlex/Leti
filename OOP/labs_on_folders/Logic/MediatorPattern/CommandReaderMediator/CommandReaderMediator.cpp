#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller){
    this->player_controller = player_controller;
    this->game_controller = game_controller;
    this->log_controller = log_controller;
};

//send
void CommandReaderMediator::send(std::string message){
    if (message == "Right")
        this->player_controller->move(Right);
    if (message == "Left")
        this->player_controller->move(Left);
    if (message == "Up")
        this->player_controller->move(Up);
    if (message == "Down")
        this->player_controller->move(Down);
    if (message == "Shoot")
        this->player_controller->shoot();
    if (message == "Quit")
        this->game_controller->setGameStatus(Quit);
    if (message == "Logging"){
        this->log_controller->setParametrs();
    }
        
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->game_controller = nullptr;
    this->player_controller = nullptr;
};
