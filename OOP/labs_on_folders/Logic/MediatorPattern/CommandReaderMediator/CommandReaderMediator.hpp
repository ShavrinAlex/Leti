#include "../Mediator.hpp"
#include "../../Controllers/EntitiesControllers/PlayerController/PlayerController.hpp"
#include "../../Controllers/GameController/GameController.hpp"
#include "../../Controllers/LogController/LogController.hpp"
#include <map>

//typedef std::map <std::string, sf::Keyboard::Key> Commands;
typedef std::map <GameControllCommands, Direction> PlayerMoveCommands;
typedef std::map <GameControllCommands, GameStatus> GameStatesCommands;
typedef std::map <GameControllCommands, LogLevels> LogLevelsCommands;
typedef std::map <GameControllCommands, LogCout> LogCoutCommands;

//sf::Keyboard::Key
class CommandReaderMediator: public Mediator<GameControllCommands>{
    private:
        PlayerController* player_controller;
        GameController* game_controller;
        LogController* log_controller;

        //Commands commands;
        PlayerMoveCommands player_move_commands = {{MovePlayerRight, Right}, {MovePlayerLeft, Left}, {MovePlayerUp, Up}, {MovePlayerDown, Down}};
        GameStatesCommands game_states_commands = {{QuitGame, Quit}};
        LogLevelsCommands log_levels_commands = {{SetErrorsLogLevel, Errors}, {SetProcessesLogLevel, Processes}, {SetGameStatesLogLevel, GameStates}};
        LogCoutCommands log_cout_commands = {{AddConsoleLogStream, Console}, {AddFileLogStream, File}, {RemoveConsoleLogStream, Console}, {RemoveFileLogStream, File}};
    public:
        //initialization
        CommandReaderMediator(PlayerController* player_controller, GameController* game_controller, LogController* log_controller);

        //send
        void send(GameControllCommands message) override;

        //destruction
        ~CommandReaderMediator();
};
