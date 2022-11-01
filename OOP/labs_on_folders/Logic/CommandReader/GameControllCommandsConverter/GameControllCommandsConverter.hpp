#include <string>
#include <map>
#include <SFML/Graphics.hpp>

typedef std::map <std::string, sf::Keyboard::Key> Commands;

//this class convert string with command to game and set it in commands in mediator
class GameControllCommandsConverter{
    private:
        Commands dict_commands;
        Commands commands;

        //filling dict_commands
        void createDictionary();

        //default commands
        void createDefaultCommands();
    public:
        //initialization
        GameControllCommandsConverter();

        //create comands to game
        void setCommand(std::string command_line);

        //converte string key to sf::Keyboard::Key
        sf::Keyboard::Key convert(std::string key);

        //get commands after convert
        Commands getCommands();
};
