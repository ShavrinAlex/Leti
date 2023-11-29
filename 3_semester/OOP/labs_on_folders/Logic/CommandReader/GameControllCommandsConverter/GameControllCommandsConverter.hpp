#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include "../../Utility/Enumerations.hpp"

typedef std::map <std::string, sf::Keyboard::Key> StrCommands;
typedef std::map <std::string, GameControllCommands> StrCommandsName;

//this class convert string with command to game and set it in commands in mediator
class GameControllCommandsConverter{
    private:
        StrCommands dict_commands;
        StrCommandsName dict_commands_name;

        //filling dict_commands
        void createCommandDictionary();

        //filling dict_commands_name
        void createCommandNameDictionary();
    public:
        //initialization
        GameControllCommandsConverter();

        //check correct command name
        bool isCorrectCommandName(std::string command);

        //check correct command
        bool isCorrectCommand(std::string command);

        //convert string key to sf::Keyboard::Key
        sf::Keyboard::Key convertCommand(std::string key);

        //convert string name command to enum
        GameControllCommands convertCommandName(std::string command);
};
