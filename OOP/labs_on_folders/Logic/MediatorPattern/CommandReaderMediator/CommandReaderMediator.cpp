#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(CommandReader* com_reader, PlayerController* player_controller, GameController* game_controller){
    this->com_reader = com_reader;
    this->player_controller = player_controller;
    this->game_controller = game_controller;
};

//send
void CommandReaderMediator::send(KeyboardCommand message, GameElement* element){
    if (element == this->com_reader){
        switch(message){
            case D:
                this->player_controller->move(Right);
                break;
            case A:
                this->player_controller->move(Left);
                break;
            case W:
                this->player_controller->move(Up);
                break;
            case S:
                this->player_controller->move(Down);
                break;
            case Q:
                this->game_controller->setGameStatus(Quit);
                break;
        }
    }
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->com_reader = nullptr;
    this->game_controller = nullptr;
    this->player_controller = nullptr;
};
