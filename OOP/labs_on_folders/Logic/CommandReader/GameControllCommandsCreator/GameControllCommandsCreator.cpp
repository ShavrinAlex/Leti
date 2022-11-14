#include "GameControllCommandsCreator.hpp"
#include "../../Utility/Enumerations.hpp"

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

        GameControllCommands enum_command = this->converter->convertCommandName(command);
        sf::Keyboard::Key sf_key = this->converter->convertCommand(key);

        auto key_to_find = this->commands.find(enum_command);
        if (key_to_find != this->commands.end()){
            this->commands[enum_command] = sf_key;
        }
    }
};

//default commands
void GameControllCommandsCreator::createDefaultCommands(){
    //player commands
    this->commands.emplace(MovePlayerRight, sf::Keyboard::D);
    this->commands.emplace(MovePlayerLeft, sf::Keyboard::A);
    this->commands.emplace(MovePlayerUp, sf::Keyboard::W);
    this->commands.emplace(MovePlayerDown, sf::Keyboard::S);
    this->commands.emplace(PlayerShoot, sf::Keyboard::Space);
    //log commands
    this->commands.emplace(SetErrorsLogLevel, sf::Keyboard::Num0);
    this->commands.emplace(SetProcessesLogLevel, sf::Keyboard::Num1);
    this->commands.emplace(SetGameStatesLogLevel, sf::Keyboard::Num2);
    this->commands.emplace(AddConsoleLogStream, sf::Keyboard::Num6);
    this->commands.emplace(AddFileLogStream, sf::Keyboard::Num7);
    this->commands.emplace(RemoveConsoleLogStream, sf::Keyboard::F6);
    this->commands.emplace(RemoveFileLogStream, sf::Keyboard::F7);
    //game commands
    this->commands.emplace(QuitGame, sf::Keyboard::Q);
};

//get commands after convert
Commands GameControllCommandsCreator::getCommands(){
    return this->commands;
};

//destruction
GameControllCommandsCreator::~GameControllCommandsCreator(){
    delete this->converter;
};
