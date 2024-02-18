#include "LevelContext.hpp"

//initialization
LevelContext::LevelContext(){
    this->strategy = nullptr;
};

//set strategy
void LevelContext::setStrategy(LevelStrategy* strategy){
    this->strategy = strategy;
};

//create level
Map* LevelContext::createLevel(){
    return this->strategy->generateLevel();
};

//destruction
LevelContext::~LevelContext(){
    this->strategy = nullptr;
};
