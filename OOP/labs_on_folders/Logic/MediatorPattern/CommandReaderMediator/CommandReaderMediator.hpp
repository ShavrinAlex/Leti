#include "../Mediator.hpp"
#include "../../CommandReader/CommandReader.hpp"
#include "../../Controllers/PlayerController/PlayerController.hpp"
#include "../../Controllers/GameController/GameController.hpp"
#include "../../Utility/Enumerations.hpp"

class CommandReaderMediator: public Mediator{
    private:
        CommandReader* com_reader;
        PlayerController* player_controller;
        GameController* game_controller;
    public:
        //initialization
        CommandReaderMediator(CommandReader* com_reader, PlayerController* player_controller, GameController* game_controller);

        //send
        void send(KeyboardCommand message, GameElement* element);

        //destruction
        ~CommandReaderMediator();
};
