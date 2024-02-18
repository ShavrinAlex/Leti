#include "GameController.hpp"

//initialization
GameController::GameController(Game* game, Player* player){
    this->game = game;
    this->player = player;
    this->player->addObserver(this);
};

//set game status
void GameController::setGameStatus(GameStatus status){
    this->game->setGameStatus(status);
};

//update
void GameController::update(){
    if (this->player->getHealth() <= 0){
        this->game->setGameStatus(Loose);
    }
};

//destruction
GameController::~GameController(){
    this->game = nullptr;
};
