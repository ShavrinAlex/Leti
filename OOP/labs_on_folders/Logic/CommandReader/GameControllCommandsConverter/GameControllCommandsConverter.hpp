#include <string>
#include <map>
#include <SFML/Graphics.hpp>

typedef std::map <std::string, char> Commands;

//this class convert string with command to game and set it in commands in mediator
class GameControllCommandsConverter{
    private:
        Commands commands;
    public:
        //converte string to command
        void convert(std::string command_line);

        //get commands after convert
        Commands getCommands();
};
