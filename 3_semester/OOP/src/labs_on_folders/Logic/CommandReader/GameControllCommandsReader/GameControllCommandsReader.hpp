#pragma once
#include <string>
#include <fstream>
#include "../GameControllCommandsCreator/GameControllCommandsCreator.hpp"

// this class read file with game controll commands an convert there to comands in mediator
class GameControllCommandsReader: public GameElement<Log*>{
    private:
        std::ifstream file;
        GameControllCommandsCreator commands_creator;
    public:
        //initialization
        GameControllCommandsReader(std::string file_name);

        //read file
        Commands readCommands();

        //destruction
        ~GameControllCommandsReader();
};
