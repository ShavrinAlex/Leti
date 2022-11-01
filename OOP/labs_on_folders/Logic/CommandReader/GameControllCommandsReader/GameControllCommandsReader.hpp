#include <string>
#include <fstream>
#include "../GameControllCommandsConverter/GameControllCommandsConverter.hpp"

// this class read file with game controll commands an convert there to comands in mediator
class GameControllCommandsReader{
    private:
        std::ifstream file;
        GameControllCommandsConverter converter;
    public:
        //initialization
        GameControllCommandsReader(std::string file_name);

        //read file
        Commands readCommands();

        //destruction
        ~GameControllCommandsReader();
};
