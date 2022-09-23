#include "Cell.hpp"

//initialization
Cell::Cell(bool is_wall = false, bool is_here_player = false){
    this->is_wall = is_wall;
    this->is_here_player= is_here_player;
};

//check is wall
bool Cell::isWall(){
    return is_wall;
};

//check player is here
bool Cell::isHerePlayer(){
    return is_here_player;
};

//set player
void Cell::setPlayer(bool is_here_player){
    this->is_here_player = is_here_player;
};
