#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(CommandReader* com_reader, PlayerController* player_controller, GameController* game_controller){
    this->com_reader = com_reader;
    this->player_controller = player_controller;
    this->game_controller = game_controller;
};

//send
void CommandReaderMediator::send(std::string message, GameElement* element){
    if (element == this->com_reader){
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
    }
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->com_reader = nullptr;
    this->game_controller = nullptr;
    this->player_controller = nullptr;
};
