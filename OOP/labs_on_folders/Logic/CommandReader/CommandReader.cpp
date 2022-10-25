#include "CommandReader.hpp"
#include <SFML/Graphics.hpp>

//read kyboard
void CommandReader::getPressedKey(){
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
        this->mediator->send("Right");
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))){
        this->mediator->send("Left");
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))){
        this->mediator->send("Up");
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))){
        this->mediator->send("Down");
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))){
        this->mediator->send("Shoot");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        this->mediator->send("Quit");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
        this->mediator->send("Logging");
    }
};
