#include "CommandReaderMediator.hpp"

//initialization
CommandReaderMediator::CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller){
    this->player_controller = player_controller;
    this->game_controller = game_controller;
    this->log_controller = log_controller;
    
    GameControllCommandsReader gccr = GameControllCommandsReader("Commands.txt");
    this->commands = gccr.readCommands();
};

//send
void CommandReaderMediator::send(sf::Keyboard::Key message){
    //________________PLAYER___________________
    if (message == this->commands["Right"]){
        this->player_controller->move(Right);
    }
    if (message == this->commands["Left"]){
        this->player_controller->move(Left);
    }
    if (message == this->commands["Up"]){
        this->player_controller->move(Up);
    }
    if (message == this->commands["Down"]){
        this->player_controller->move(Down);
    }
    if (message == this->commands["Shoot"]){
         this->player_controller->shoot();
    }
    //____________________GAME________________________
    if (message == this->commands["Quit"]){
        this->game_controller->setGameStatus(Quit);
    }
    //__________________LOG_LEVEL_____________________
    if (message == this->commands["SetErrorsLogLevel"]){
        this->log_controller->setLevel(Errors);
    }
    if (message == this->commands["SetProcessesLogLevel"]){
        this->log_controller->setLevel(Processes);
    }
    if (message == this->commands["SetGameStatesLogLevel"]){
        this->log_controller->setLevel(GameStates);
    }
    //_____________________LOG_STREAM________________________
    if (message == this->commands["AddConsoleLogStream"]){
        this->log_controller->addStream(Console);
    }
    if (message == this->commands["AddFileLogStream"]){
        this->log_controller->addStream(File);
    }
    if (message == this->commands["RemoveConsoleLogStream"]){
        this->log_controller->removeStream(Console);
    }
    if (message == this->commands["RemoveFileLogStream"]){
        this->log_controller->removeStream(File);
    }
    /*
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
    */
};

//destruction
CommandReaderMediator::~CommandReaderMediator(){
    this->game_controller = nullptr;
    this->player_controller = nullptr;
};
