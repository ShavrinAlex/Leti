#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller){
    this->player_controller = player_controller;
    this->game_controller = game_controller;
    this->log_controller = log_controller;

    //set comands from file
};

//send
void CommandReaderMediator::send(sf::Keyboard::Key message){
    switch (message){
        //_____________________________________________PLAYER______________________________________________________
        case sf::Keyboard::Right:
        case sf::Keyboard::D:
            this->player_controller->move(Right);
            break;
        case sf::Keyboard::Left:
        case sf::Keyboard::A:
            this->player_controller->move(Left);
            break;
        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            this->player_controller->move(Up);
            break;
        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            this->player_controller->move(Down);
            break;
        case sf::Keyboard::Space:
            this->player_controller->shoot();
            break;
    //_______________________________________________GAME______________________________________________________
        case sf::Keyboard::Q:
            this->game_controller->setGameStatus(Quit);
            break;
    //_____________________________________________LOG_LEVEL___________________________________________________
        case sf::Keyboard::Num0:
            this->log_controller->setLevel(Errors);
            break;
        case sf::Keyboard::Num1:
            this->log_controller->setLevel(Processes);
            break;
        case sf::Keyboard::Num2:
            this->log_controller->setLevel(GameStates);
            break;
    //_____________________________________________LOG_STREAM__________________________________________________
        case sf::Keyboard::Num6:
            this->log_controller->addStream(Console);
            break;
        case sf::Keyboard::F6:
            this->log_controller->removeStream(Console);
            break;
        case sf::Keyboard::Num7:
            this->log_controller->addStream(File);
            break;
        case sf::Keyboard::F7:
            this->log_controller->removeStream(File);
            break;
        default:
            break;
    }
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->game_controller = nullptr;
    this->player_controller = nullptr;
};
