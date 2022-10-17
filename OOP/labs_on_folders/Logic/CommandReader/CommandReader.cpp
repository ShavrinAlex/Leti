#include "CommandReader.hpp"
#include "../Utility/Enumerations.hpp"

//read kyboard
void CommandReader::getPressedKey(){
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
        mediator->send(D, this);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))){
        mediator->send(A, this);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))){
        mediator->send(W, this);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))){
        mediator->send(S, this);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        mediator->send(Q, this);
    }
};
