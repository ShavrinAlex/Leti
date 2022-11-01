#include "GameControllCommandsConverter.hpp"

//converte string to command
void GameControllCommandsConverter::convert(std::string command_line){
    size_t pos_eq = command_line.find('=');
    if (pos_eq != std::string::npos){
        std::string command = command_line.substr(0, pos_eq - 1);
        char key = command_line.at(pos_eq + 1);
        this->commands.emplace(command, key);
    }
};

//get commands after convert
Commands GameControllCommandsConverter::getCommands(){
    return this->commands;
};
