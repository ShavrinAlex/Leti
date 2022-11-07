#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

typedef std::map <std::string, sf::Keyboard::Key> Commands;

//this class convert string with command to game and set it in commands in mediator
class GameControllCommandsConverter{
    private:
        Commands dict_commands;

        //filling dict_commands
        void createDictionary();
    public:
        //initialization
        GameControllCommandsConverter();

        //converte string key to sf::Keyboard::Key
        sf::Keyboard::Key convert(std::string key);
};
