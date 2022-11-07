#include "GameControllCommandsReader.hpp"

//initialization
GameControllCommandsReader::GameControllCommandsReader(std::string file_name){
    this->file.open(file_name);
};

//read file
Commands GameControllCommandsReader::readCommands(){
    std::string line;
    
    while (getline(file, line)){
        this->commands_creator.setCommand(line);
    }

    return commands_creator.getCommands();
};

//destruction
GameControllCommandsReader::~GameControllCommandsReader(){
    this->file.close();
};
