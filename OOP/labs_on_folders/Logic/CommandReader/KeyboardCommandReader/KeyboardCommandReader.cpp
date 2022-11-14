#include "KeyboardCommandReader.hpp"

//initialization
KeyboardCommandReader::KeyboardCommandReader(){
    GameControllCommandsReader gccr = GameControllCommandsReader("Commands.txt");
    this->commands = gccr.readCommands();
};

//search command
GameControllCommands KeyboardCommandReader::searchCommand(sf::Keyboard::Key button){
    GameControllCommands command = Nothing;
    for (auto it = this->commands.begin(); it != this->commands.end(); ++it){
        if (it->second == button){
            command = it->first;
            break;
        }
    }
    return command;
};

//read kyboard
void KeyboardCommandReader::readCommand(std::shared_ptr<sf::Event> event){
    if (event->type == sf::Event::KeyReleased){
        //adapt sf::keyboard::key to enum GameControllCommands and send it to mediator
        this->mediator->send(this->searchCommand(event->key.code));
    }
};
