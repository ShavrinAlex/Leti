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

//get mediator
template <typename T>
Mediator<T>* GameElement<T>::getMediator(){
    return this->mediator;
};  

//destruction
template <typename T>
GameElement<T>::~GameElement(){
    this->mediator = nullptr;
};
