#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include "../GameControllCommandsConverter/GameControllCommandsConverter.hpp"

typedef std::map <GameControllCommands, sf::Keyboard::Key> Commands;

//this class set commands to game in commands in mediator
class GameControllCommandsCreator{
    private:
        Commands commands;
        GameControllCommandsConverter* converter;

        //default commands
        void createDefaultCommands();
    public:
        //initialization
        GameControllCommandsCreator();

        //create comands to game
        void setCommand(std::string command_line);

        //get commands after convert
        Commands getCommands();

        //destruction
        ~GameControllCommandsCreator();
};  
