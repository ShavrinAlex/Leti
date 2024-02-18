#include "KeyboardCommandReader.hpp"

//initialization
KeyboardCommandReader::KeyboardCommandReader(CommandAdapter* adapter){
    this->adapter = adapter;
};

//read kyboard
void KeyboardCommandReader::readCommand(std::shared_ptr<sf::Event> event){
    if (event->type == sf::Event::KeyReleased){
        //adapt sf::keyboard::key to enum GameControllCommands and send it to mediator
        this->mediator->send(this->adapter->adapt(event->key.code));
    }
};
