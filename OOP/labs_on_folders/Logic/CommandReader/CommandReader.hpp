#pragma once
#include <SFML/Graphics.hpp>
#include "../MediatorPattern/GameElement/GameElementDescription.hpp"
#include <memory>

class CommandReader: public GameElement<std::string>{
    public:
        //read kyboard
        void getPressedKey(std::shared_ptr<sf::Event> event);
};
