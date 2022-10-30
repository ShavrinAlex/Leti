#include "CommandReader.hpp"

//read kyboard
void CommandReader::getPressedKey(std::shared_ptr<sf::Event> event){
    if (event->type == sf::Event::KeyReleased){
        switch (event->key.code){
        //_____________________________________________PLAYER______________________________________________________
            case sf::Keyboard::Right:
            case sf::Keyboard::D:
                this->mediator->send("Right");
                break;
            case sf::Keyboard::Left:
            case sf::Keyboard::A:
                this->mediator->send("Left");
                break;
            case sf::Keyboard::Up:
            case sf::Keyboard::W:
                this->mediator->send("Up");
                break;
            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                this->mediator->send("Down");
                break;
            case sf::Keyboard::Space:
                this->mediator->send("Shoot");
                break;
        //_______________________________________________GAME______________________________________________________
            case sf::Keyboard::Q:
                this->mediator->send("Quit");
                break;
        //_____________________________________________LOG_LEVEL___________________________________________________
            case sf::Keyboard::Num0:
                this->mediator->send("SetErrorsLogLevel");
                break;
            case sf::Keyboard::Num1:
                this->mediator->send("SetProcessesLogLevel");
                break;
            case sf::Keyboard::Num2:
                this->mediator->send("SetGameStatesLogLevel");
                break;
        //_____________________________________________LOG_STREAM__________________________________________________
            case sf::Keyboard::Num6:
                this->mediator->send("AddCnsoleLogStream");
                break;
            case sf::Keyboard::F6:
                this->mediator->send("RemoveCnsoleLogStream");
                break;
            case sf::Keyboard::Num7:
                this->mediator->send("AddFileLogStream");
                break;
            case sf::Keyboard::F7:
                this->mediator->send("RemoveFileLogStream");
                break;
            default:
                break;
        }
    }
};
