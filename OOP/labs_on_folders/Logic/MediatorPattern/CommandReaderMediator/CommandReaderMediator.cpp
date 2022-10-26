#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller){
    this->player_controller = player_controller;
    this->game_controller = game_controller;
    this->log_controller = log_controller;
};

//send
void CommandReaderMediator::send(std::string message){
    //________________PLAYER__________________
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
    //________________GAME____________________
    if (message == "Quit")
        this->game_controller->setGameStatus(Quit);
    //________________LOG_LEVEL_______________
    if (message == "AddErrorsLogLevel"){
        this->log_controller->addLevel(Errors);
    }
    if (message == "RemoveErrorsLogLevel"){
        this->log_controller->removeLevel(Errors);
    }
    if (message == "AddProcessesLogLevel"){
        this->log_controller->addLevel(Processes);
    }
    if (message == "RemoveProcessesLogLevel"){
        this->log_controller->removeLevel(Processes);
    }
    if (message == "AddGameStatesLogLevel"){
        this->log_controller->addLevel(GameStates);
    }
    if (message == "RemoveGameStatesLogLevel"){
        this->log_controller->removeLevel(GameStates);
    }
    //________________LOG_STREAM_______________
    if (message == "AddCnsoleLogStream"){
        this->log_controller->addStream(Console);
    }
    if (message == "RemoveCnsoleLogStream"){
        this->log_controller->removeStream(Console);
    }
    if (message == "AddFileLogStream"){
        this->log_controller->addStream(File);
    }
    if (message == "RemoveFileLogStream"){
        this->log_controller->removeStream(File);
    }
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->game_controller = nullptr;
    this->player_controller = nullptr;
};
