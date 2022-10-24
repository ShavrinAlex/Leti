#include "../Mediator.hpp"
#include "../../CommandReader/CommandReader.hpp"
#include "../../Controllers/EntitiesControllers/PlayerController/PlayerController.hpp"
#include "../../Controllers/GameController/GameController.hpp"

class CommandReaderMediator: public Mediator{
    private:
        CommandReader* com_reader;
        PlayerController* player_controller;
        GameController* game_controller;
    public:
        //initialization
        CommandReaderMediator(CommandReader* com_reader, PlayerController* player_controller, GameController* game_controller);

        //send
        void send(std::string  message, GameElement* element) override;

        //destruction
        ~CommandReaderMediator();
};
