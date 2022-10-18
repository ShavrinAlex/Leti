#include "CommandReader.hpp"

//read kyboard
void CommandReader::getPressedKey(){
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
        mediator->send("Right", this);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))){
        mediator->send("Left", this);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))){
        mediator->send("Up", this);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))){
        mediator->send("Down", this);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))){
        mediator->send("Shoot", this);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        mediator->send("Quit", this);
    }
};
