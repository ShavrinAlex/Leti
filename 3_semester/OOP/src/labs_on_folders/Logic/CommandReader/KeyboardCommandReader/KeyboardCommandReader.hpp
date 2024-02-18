#pragma once
#include <SFML/Graphics.hpp>
#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"
#include "../CommandAdapterPattern/CommandAdapter.hpp"
#include <memory>

class KeyboardCommandReader: public GameElement<GameControllCommands>{
    private:
        CommandAdapter* adapter;
    public:
        //initialization
        KeyboardCommandReader(CommandAdapter* adapter);

        //read kyboard command
        void readCommand(std::shared_ptr<sf::Event> event);
};
