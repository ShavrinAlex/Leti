#include "../Mediator.hpp"
#include "../../Controllers/EntitiesControllers/PlayerController/PlayerController.hpp"
#include "../../Controllers/GameController/GameController.hpp"
#include "../../Controllers/LogController/LogController.hpp"
#include <map>

class CommandReaderMediator: public Mediator<GameControllCommands>{
    private:
        PlayerController* player_controller;
        GameController* game_controller;
        LogController* log_controller;

        //Commands commands;
        typedef std::map <GameControllCommands, std::function<void(CommandReaderMediator *)>> MediatorCommands;
        MediatorCommands mediator_commands;

        void createMediatorCommands();
    public:
        //initialization
        CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller);

        //send
        void send(GameControllCommands message) override;

        //destruction
        ~CommandReaderMediator();
};
