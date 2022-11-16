#include "GameControllCommandsCreator.hpp"
#include "../../Utility/Enumerations.hpp"
#include <iostream>
//initialization
GameControllCommandsCreator::GameControllCommandsCreator(){
    this->createDefaultCommands();
    this->converter = new GameControllCommandsConverter();
};

//check repeat command
bool GameControllCommandsCreator::isRepeatCommand(sf::Keyboard::Key key){
    for (auto it = this->file_commands.begin(); it != this->file_commands.end(); ++it){
        if (it->second == key){
            return true;
        }
    }
    return false;
};

//check full commands
bool GameControllCommandsCreator::isFullCommands(Commands commands){
    for (auto it = default_commands.begin(); it != this->default_commands.end(); ++it){
        if (this->file_commands.find(it->first) == this->file_commands.end()){
            return false;
        }
    }
    return true;
};

//converte string to command
int GameControllCommandsCreator::setCommand(std::string command_line){
    //std::cout<<"setCommand\n";
    size_t pos_eq = command_line.find('=');
    if (pos_eq != std::string::npos && pos_eq != command_line.length() - 1 && pos_eq != 0){
        std::string command = command_line.substr(0, pos_eq - 1);
        std::string key = command_line.substr(pos_eq + 2);

        GameControllCommands enum_command;
        if (this->converter->isCorrectCommandName(command)){
            enum_command = this->converter->convertCommandName(command);
        } else{
            //logging
            Log* log = new Log(Errors, "Error!!! Invalid command name {" + command + "}");
            this->mediator->send(log);
            delete log;

            return -1;
        }

        sf::Keyboard::Key sf_key;
        if (this->converter->isCorrectCommand(key)){
            sf_key = this->converter->convertCommand(key);
        } else{
            //logging
            Log* log = new Log(Errors, "Error!!! Invalid command key {" + key + "}");
            this->mediator->send(log);
            delete log;

            return -1;
        }
        
        if (!this->isRepeatCommand(sf_key)){
            this->file_commands.emplace(enum_command, sf_key);
        } else{
            //logging
            Log* log = new Log(Errors, "Error!!! Trying to assign one key to two commands");
            this->mediator->send(log);
            delete log;

            return -1;
        }

        return 0;
    } else{
        //logging
        Log* log = new Log(Errors, "Error!!! Incorrect form of the command file");
        this->mediator->send(log);
        delete log;

        return -1;
    }
};

//default commands
void GameControllCommandsCreator::createDefaultCommands(){
    //player commands
    this->default_commands.emplace(MovePlayerRight, sf::Keyboard::D);
    this->default_commands.emplace(MovePlayerLeft, sf::Keyboard::A);
    this->default_commands.emplace(MovePlayerUp, sf::Keyboard::W);
    this->default_commands.emplace(MovePlayerDown, sf::Keyboard::S);
    this->default_commands.emplace(PlayerShoot, sf::Keyboard::Space);
    //log commands
    this->default_commands.emplace(SetErrorsLogLevel, sf::Keyboard::Num0);
    this->default_commands.emplace(SetProcessesLogLevel, sf::Keyboard::Num1);
    this->default_commands.emplace(SetGameStatesLogLevel, sf::Keyboard::Num2);
    this->default_commands.emplace(AddConsoleLogStream, sf::Keyboard::Num6);
    this->default_commands.emplace(AddFileLogStream, sf::Keyboard::Num7);
    this->default_commands.emplace(RemoveConsoleLogStream, sf::Keyboard::F6);
    this->default_commands.emplace(RemoveFileLogStream, sf::Keyboard::F7);
    //game commands
    this->default_commands.emplace(QuitGame, sf::Keyboard::Q);
};

//get commands after convert
Commands GameControllCommandsCreator::getCommands(){
    return this->file_commands;
};

//get default commands
Commands GameControllCommandsCreator::getDefaultCommands(){
    return this->default_commands;
};

//destruction
GameControllCommandsCreator::~GameControllCommandsCreator(){
    delete this->converter;
};
