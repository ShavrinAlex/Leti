#pragma once
#include "../../Map/Map.hpp"

template <typename ... Rules>
class LevelGenerator{
    private:
        Map* map;

        //apply rules
        template <typename Rule>
        void applyer();

    public:
        //initialization
        LevelGenerator();

        //create map
        void createMap(GameController* game_controller, Player* player, Mediator<Log*>* mediator, int map_height, int map_width);

        //generate
        Map* generate();
};

//initialization
template <typename ... Rules>
LevelGenerator<Rules ...>::LevelGenerator(){
    //create map
    this->map = nullptr;
};

//create map
template <typename ... Rules>
void LevelGenerator<Rules ...>::createMap(GameController* game_controller, Player* player, Mediator<Log*>* mediator, int map_height, int map_width){
    this->map = new Map(map_width, map_height, mediator);
    this->map->setPlayer(player);
    this->map->setGameController(game_controller);
};

//apply rules
template <typename ... Rules>
template <typename Rule>
void LevelGenerator<Rules ...>::applyer(){
    Rule rule;
    rule.apply(this->map);
};


template <typename ... Rules>
Map* LevelGenerator<Rules ...>::generate(){
    (applyer<Rules>(), ...);
    return this->map;
};
