#include "LevelTwo.hpp"
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

//initialization
LevelTwo::LevelTwo(GameController* game_controller, Player* player, Mediator<Log*>* mediator){
    //create map
    this->map = new Map(MAP_WIDTH, MAP_HEIGHT, mediator);
    map->setPlayer(player);
    
    map->setGameController(game_controller);
};

//generate level
Map* LevelTwo::generateLevel(){
    this->level_generator.applyRules(this->map);
    return this->map;
};
