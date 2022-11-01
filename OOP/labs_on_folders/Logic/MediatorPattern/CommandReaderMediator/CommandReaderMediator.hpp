#include "../Mediator.hpp"
#include "../../Controllers/EntitiesControllers/PlayerController/PlayerController.hpp"
#include "../../Controllers/GameController/GameController.hpp"
#include "../../Controllers/LogController/LogController.hpp"
#include "../../CommandReader/GameControllCommandsReader/GameControllCommandsReader.hpp"
#include <map>

typedef std::map <std::string, sf::Keyboard::Key> Commands;

class CommandReaderMediator: public Mediator<sf::Keyboard::Key>{
    private:
        PlayerController* player_controller;
        GameController* game_controller;
        LogController* log_controller;

        Commands commands;
    public:
        //initialization
        CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller);

        //send
        void send(sf::Keyboard::Key message) override;

        //destruction
        ~CommandReaderMediator();
};
