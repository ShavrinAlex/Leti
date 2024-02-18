#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller){
    this->player_controller = player_controller;
    this->game_controller = game_controller;
    this->log_controller = log_controller;
    createMediatorCommands();
};

void CommandReaderMediator::createMediatorCommands(){
    this->mediator_commands.emplace(MovePlayerRight, [](CommandReaderMediator *obj){obj->player_controller->move(Right);});
    this->mediator_commands.emplace(MovePlayerLeft, [](CommandReaderMediator *obj){obj->player_controller->move(Left);});
    this->mediator_commands.emplace(MovePlayerUp, [](CommandReaderMediator *obj){obj->player_controller->move(Up);});
    this->mediator_commands.emplace(MovePlayerDown, [](CommandReaderMediator *obj){obj->player_controller->move(Down);});
    this->mediator_commands.emplace(PlayerShoot, [](CommandReaderMediator *obj){obj->player_controller->shoot();});
    this->mediator_commands.emplace(QuitGame, [](CommandReaderMediator *obj){obj->game_controller->setGameStatus(Quit);});
    this->mediator_commands.emplace(SetErrorsLogLevel, [](CommandReaderMediator *obj){obj->log_controller->setLevel(Errors);});
    this->mediator_commands.emplace(SetProcessesLogLevel, [](CommandReaderMediator *obj){obj->log_controller->setLevel(Processes);});
    this->mediator_commands.emplace(SetGameStatesLogLevel, [](CommandReaderMediator *obj){obj->log_controller->setLevel(GameStates);});
    this->mediator_commands.emplace(AddConsoleLogStream, [](CommandReaderMediator *obj){obj->log_controller->addStream(Console);});
    this->mediator_commands.emplace(AddFileLogStream, [](CommandReaderMediator *obj){obj->log_controller->addStream(File);});
    this->mediator_commands.emplace(RemoveConsoleLogStream, [](CommandReaderMediator *obj){obj->log_controller->removeStream(Console);});
    this->mediator_commands.emplace(RemoveFileLogStream, [](CommandReaderMediator *obj){obj->log_controller->removeStream(File);});
};

//send 
void CommandReaderMediator::send(GameControllCommands message){
    auto search = this->mediator_commands.find(message);
    if (search != this->mediator_commands.end()){
       search->second(this);
    }
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->game_controller = nullptr;
    this->player_controller = nullptr;
    this->log_controller =  nullptr;
};
