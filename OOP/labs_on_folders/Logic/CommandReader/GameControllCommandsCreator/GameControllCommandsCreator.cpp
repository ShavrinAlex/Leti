#include "GameControllCommandsCreator.hpp"

//initialization
GameControllCommandsCreator::GameControllCommandsCreator(){
    this->createDefaultCommands();
    this->converter = new GameControllCommandsConverter();
};

//converte string to command
void GameControllCommandsCreator::setCommand(std::string command_line){
    size_t pos_eq = command_line.find('=');
    if (pos_eq != std::string::npos){
        std::string command = command_line.substr(0, pos_eq - 1);
        std::string key = command_line.substr(pos_eq + 2);

        auto key_to_find = this->commands.find(command);
        if (key_to_find != this->commands.end()){
            this->commands[command] = this->converter->convert(key);
        } else{
            this->commands.emplace(command, this->converter->convert(key));
        }
    }
};

//default commands
void GameControllCommandsCreator::createDefaultCommands(){
    this->commands.emplace("Right", sf::Keyboard::D);
    this->commands.emplace("Left", sf::Keyboard::A);
    this->commands.emplace("Up", sf::Keyboard::W);
    this->commands.emplace("Down", sf::Keyboard::S);
    this->commands.emplace("Shoot", sf::Keyboard::Space);
    this->commands.emplace("Quit", sf::Keyboard::Q);
    this->commands.emplace("SetErrorsLogLevel", sf::Keyboard::Num0);
    this->commands.emplace("SetProcessesLogLevel", sf::Keyboard::Num1);
    this->commands.emplace("SetGameStatesLogLevel", sf::Keyboard::Num2);
    this->commands.emplace("AddConsoleLogStream", sf::Keyboard::Num6);
    this->commands.emplace("AddFileLogStream", sf::Keyboard::Num7);
    this->commands.emplace("RemoveConsoleLogStream", sf::Keyboard::F6);
    this->commands.emplace("RemoveFileLogStream", sf::Keyboard::F7);
};

//get commands after convert
Commands GameControllCommandsCreator::getCommands(){
    return this->commands;
};

//destruction
GameControllCommandsCreator::~GameControllCommandsCreator(){
    delete this->converter;
};
