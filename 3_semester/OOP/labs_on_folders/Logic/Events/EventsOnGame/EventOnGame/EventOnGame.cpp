#include "EventOnGame.hpp"

//initialization
EventOnGame::EventOnGame(GameController* game_controller){
    this->game_controller = game_controller;
};

//destruction
EventOnGame::~EventOnGame(){
    this->game_controller = nullptr;
};
