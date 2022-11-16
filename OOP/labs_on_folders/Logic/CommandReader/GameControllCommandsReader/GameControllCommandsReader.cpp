#include "GameControllCommandsReader.hpp"
#include <iostream>
//initialization
GameControllCommandsReader::GameControllCommandsReader(std::string file_name){
    this->file.open(file_name);
};

//read file
Commands GameControllCommandsReader::readCommands(){
    this->commands_creator.setMediator(this->mediator);

    std::string line;
    bool error = false;
    
    while (getline(file, line)){
        if (this->commands_creator.setCommand(line) == -1){
            error = true;
            break;
        }
    }
    if (this->commands_creator.isFullCommands(commands_creator.getCommands()) && !error){
        //logging
        Log* log = new Log(Processes, "Commands file was successfully read. Set controll keys from file");
        this->mediator->send(log);
        delete log;

        return commands_creator.getCommands();
    } else {
        if (!error){
            //logging
            Log* log = new Log(Errors, "Error!!! Not all commands are installed in the commands file");
            this->mediator->send(log);
            delete log;
        }

        //logging
        Log* log = new Log(Processes, "Commands file was read with errors. Set default controll keys");
        this->mediator->send(log);
        delete log;

        return commands_creator.getDefaultCommands();
    }
};

//destruction
GameControllCommandsReader::~GameControllCommandsReader(){
    this->file.close();
};
