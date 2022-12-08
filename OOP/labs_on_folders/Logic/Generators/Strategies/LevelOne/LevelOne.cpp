#include "LevelOne.hpp"

//initialization
LevelOne::LevelOne(GameController* game_controller, Player* player, Mediator<Log*>* mediator, int map_height, int map_width){
    ///create map
    this->level_generator.createMap(game_controller, player, mediator, map_height, map_width);
};

//generate level
Map* LevelOne::generateLevel(){
    return this->level_generator.generate();
};
