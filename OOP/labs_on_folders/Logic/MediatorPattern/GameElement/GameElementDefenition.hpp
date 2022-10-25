#pragma once
#include "GameElementDescription.hpp"

//initialization
template <typename T>
GameElement<T>::GameElement(){
    this->mediator = nullptr;
};

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
