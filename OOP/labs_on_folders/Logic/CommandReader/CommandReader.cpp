#include "CommandReader.hpp"
#include <SFML/Graphics.hpp>

//read kyboard
void CommandReader::getPressedKey(){
    //_____________________________________________PLAYER______________________________________________________
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
    //_______________________________________________GAME______________________________________________________
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        this->mediator->send("Quit");
    }
    //_____________________________________________LOG_LEVEL___________________________________________________
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
        this->mediator->send("AddErrorsLogLevel");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9)){
        this->mediator->send("RemoveErrorsLogLevel");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        this->mediator->send("AddProcessesLogLevel");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
        this->mediator->send("RemoveProcessesLogLevel");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        this->mediator->send("AddGameStatesLogLevel");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)){
        this->mediator->send("RemoveGameStatesLogLevel");
    }
    //_____________________________________________LOG_STREAM__________________________________________________
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){
        this->mediator->send("AddCnsoleLogStream");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)){
        this->mediator->send("RemoveCnsoleLogStream");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)){
        this->mediator->send("AddFileLogStream");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7)){
        this->mediator->send("RemoveFileLogStream");
    }
};
