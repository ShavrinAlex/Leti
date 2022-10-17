#include "GameElement.hpp"

//set mediator
void GameElement::setMediator(Mediator* mediator){
    this->mediator = mediator;
}

//destruction
GameElement::~GameElement(){
    this->mediator = nullptr;
};
