#pragma once
#include <SFML/Graphics.hpp>
#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"
#include "../../CommandReader/GameControllCommandsReader/GameControllCommandsReader.hpp"
#include "../../Utility/Enumerations.hpp"
#include <memory>
#include <map>

//typedef std::map<GameControllCommands, sf::Keyboard::Key> Commands;

class KeyboardCommandReader: public GameElement<GameControllCommands>{
    private:
        Commands commands;

        //search command
        GameControllCommands searchCommand(sf::Keyboard::Key button);
    public:
        //initialization
        KeyboardCommandReader();

        //read kyboard command
        void readCommand(std::shared_ptr<sf::Event> event);
};
