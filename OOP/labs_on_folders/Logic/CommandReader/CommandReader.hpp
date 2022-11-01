#pragma once
#include <SFML/Graphics.hpp>
#include "../MediatorPattern/GameElement/GameElementDescription.hpp"
#include <memory>

class CommandReader: public GameElement<sf::Keyboard::Key>{
    public:
        //read kyboard
        void getPressedKey(std::shared_ptr<sf::Event> event);
};
