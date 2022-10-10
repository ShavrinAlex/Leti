#include "../Headlines/EventOnGame.hpp"

//initialization
EventOnGame::EventOnGame(Game* game){
    this->game = game;
};

//destruction
EventOnGame::~EventOnGame(){
    this->game = nullptr;
};
