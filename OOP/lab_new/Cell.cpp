#include "Cell.h"

//initialization
Cell::Cell(bool is_wall = false, bool is_here_player = false){
    this->is_wall = is_wall;
    this->is_here_player= is_here_player;
};

//check is bussy cell
bool Cell::isWall(){
    return is_wall;
};

//check hero is here
bool Cell::isHerePlayer(){
    return is_here_player;
};

//set hero
void Cell::setPlayer(bool is_here_player){
    this->is_here_player = is_here_player;
};
