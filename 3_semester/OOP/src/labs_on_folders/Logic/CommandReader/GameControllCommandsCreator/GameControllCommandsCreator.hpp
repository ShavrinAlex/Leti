#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include "../GameControllCommandsConverter/GameControllCommandsConverter.hpp"
#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"
#include "../../Logging/Log/Log.hpp"

typedef std::map <GameControllCommands, sf::Keyboard::Key> Commands;

//this class set commands to game in commands in mediator
class GameControllCommandsCreator: public GameElement<Log*>{
    private:
        Commands default_commands;
        Commands file_commands;
        GameControllCommandsConverter* converter;

        //default commands
        void createDefaultCommands();

        //check repeat command
        bool isRepeatCommand(sf::Keyboard::Key key);
    public:
        //initialization
        GameControllCommandsCreator();

        //create comands to game
        int setCommand(std::string command_line);

        //check full commands
        bool isFullCommands(Commands commands);

        //get commands after convert
        Commands getCommands();

        //get default commands
        Commands getDefaultCommands();

        //destruction
        ~GameControllCommandsCreator();
};  
