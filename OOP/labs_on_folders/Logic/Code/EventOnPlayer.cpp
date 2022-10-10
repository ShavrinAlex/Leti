#include "../Headlines/EventOnPlayer.hpp"

//initialization
EventOnPlayer::EventOnPlayer(Player* player){
    this->player = player;
};

//destruction
EventOnPlayer::~EventOnPlayer(){
    this->player = nullptr;
};