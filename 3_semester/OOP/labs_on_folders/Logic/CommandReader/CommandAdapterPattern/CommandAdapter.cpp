#include "CommandAdapter.hpp"
#include <iostream>
//initialization
CommandAdapter::CommandAdapter(Mediator<Log *>* mediator){
    GameControllCommandsReader* gccr = new GameControllCommandsReader("Commands.txt");
    gccr->setMediator(mediator);
    this->commands = gccr->readCommands();
    delete gccr;
};

//adapt command
GameControllCommands CommandAdapter::adapt(sf::Keyboard::Key button){
    //std::cout<<"adapt\n";
    GameControllCommands command = Nothing;
    for (auto it = this->commands.begin(); it != this->commands.end(); ++it){
        if (it->second == button){
            command = it->first;
            break;
        }
    }
    return command;
};
