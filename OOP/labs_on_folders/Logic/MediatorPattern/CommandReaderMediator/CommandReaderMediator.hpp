#include "../Mediator.hpp"
#include "../../Controllers/EntitiesControllers/PlayerController/PlayerController.hpp"
#include "../../Controllers/GameController/GameController.hpp"
#include "../../Controllers/LogController/LogController.hpp"
#include <map>

class CommandReaderMediator: public Mediator<sf::Keyboard::Key>{
    private:
        PlayerController* player_controller;
        GameController* game_controller;
        LogController* log_controller;
    public:
        //initialization
        CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller);

        //send
        void send(sf::Keyboard::Key message) override;

        //destruction
        ~CommandReaderMediator();
};
