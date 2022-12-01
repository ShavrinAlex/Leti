#include "LevelOne.hpp"
#define MAP_WIDTH 5
#define MAP_HEIGHT 5

//initialization
LevelOne::LevelOne(GameController* game_controller, Player* player, Mediator<Log*>* mediator){
    //create map
    std::cout<<"map created\n";
    this->map = new Map(MAP_WIDTH, MAP_HEIGHT, mediator);
    map->setPlayer(player);
    
    map->setGameController(game_controller);
    std::cout<<"controller set\n";
};

//generate level
Map* LevelOne::generateLevel(){
    std::cout<<"generate level\n";
    this->level_generator.applyRules(this->map);
    return this->map;
};
