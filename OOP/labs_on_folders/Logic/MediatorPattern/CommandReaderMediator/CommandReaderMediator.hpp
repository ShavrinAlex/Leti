#include "../Mediator.hpp"
#include "../../Controllers/EntitiesControllers/PlayerController/PlayerController.hpp"
#include "../../Controllers/GameController/GameController.hpp"
#include "../../Controllers/LogController/LogController.hpp"

class CommandReaderMediator: public Mediator<std::string>{
    private:
        PlayerController* player_controller;
        GameController* game_controller;
        LogController* log_controller;
    public:
        //initialization
        CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller);

        //send
        void send(std::string message) override;

        //destruction
        ~CommandReaderMediator();
};
