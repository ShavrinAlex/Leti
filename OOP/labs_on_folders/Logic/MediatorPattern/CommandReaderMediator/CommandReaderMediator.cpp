#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller){
    this->player_controller = player_controller;
    this->game_controller = game_controller;
    this->log_controller = log_controller;
};

//send 
void CommandReaderMediator::send(GameControllCommands message){
    if (message == PlayerShoot){
        this->player_controller->shoot();
        return;
    }
    auto search0 = this->player_move_commands.find(message);
    if (search0 != this->player_move_commands.end()){
        this->player_controller->move(search0->second);
        return;
    }

    auto search1 = this->game_states_commands.find(message);
    if (search1 != this->game_states_commands.end()){
        this->game_controller->setGameStatus(search1->second);
        return;
    }

    auto search2 = this->log_levels_commands.find(message);
    if (search2 != this->log_levels_commands.end()){
        this->log_controller->setLevel(search2->second);
        return;
    }

    auto search3 = this->log_cout_commands.find(message);
    if (search3 != this->log_cout_commands.end()){
        if (message == AddFileLogStream || message == AddConsoleLogStream){
            this->log_controller->addStream(search3->second);
        } else{
            this->log_controller->removeStream(search3->second);
        }
        return;
    }
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->game_controller = nullptr;
    this->player_controller = nullptr;
    this->log_controller =  nullptr;
};
