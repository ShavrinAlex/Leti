#include "GameControllCommandsReader.hpp"

//initialization
GameControllCommandsReader::GameControllCommandsReader(std::string file_name){
    this->file.open(file_name);
};

//read file
Commands GameControllCommandsReader::readCommands(){
    std::string line;
    
    while (getline(file, line)){
        
    }

    return converter.getCommands();
};

//destruction
GameControllCommandsReader::~GameControllCommandsReader(){
    this->file.close();
};
