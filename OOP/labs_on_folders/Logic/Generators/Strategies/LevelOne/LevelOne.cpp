#include "LevelOne.hpp"

//initialization
LevelOne::LevelOne(GameController* game_controller, Player* player, Mediator<Log*>* mediator, int map_height, int map_width){
    //create map
    this->map = new Map(map_width, map_height, mediator);
    map->setPlayer(player);
    
    map->setGameController(game_controller);
};

//generate level
Map* LevelOne::generateLevel(){
    this->level_generator.applyRules(this->map);
    return this->map;
};
