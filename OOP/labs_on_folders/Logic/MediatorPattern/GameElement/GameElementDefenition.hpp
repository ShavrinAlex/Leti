#pragma once
#include "GameElementDescription.hpp"

//set mediator
template <typename T>
void GameElement<T>::setMediator(Mediator<T>* mediator){
    this->mediator = mediator;
};

//destruction
template <typename T>
GameElement<T>::~GameElement(){
    this->mediator = nullptr;
};
