#pragma once
#include <SFML/Graphics.hpp>
#include "../../CommandReader/GameControllCommandsReader/GameControllCommandsReader.hpp"
#include "../../Utility/Enumerations.hpp"
#include "../../MediatorPattern/Mediator.hpp"
#include "../../Logging/Log/Log.hpp"

class CommandAdapter{
    private:
        Commands commands;
    public:
        //initialization
        CommandAdapter(Mediator<Log *>* mediator);

        //adapt command
        GameControllCommands adapt(sf::Keyboard::Key botton);
};
