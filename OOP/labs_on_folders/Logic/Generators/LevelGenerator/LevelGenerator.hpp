#pragma once
#include "../../Map/Map.hpp"

template <typename ... Rules>
class LevelGenerator{
public:
    void applyRules(Map *map);

    //apply rules
    template <typename Rule>
    void applyer(Map *map);
};

//apply rules
template <typename ... Rules>
template <typename Rule>
void LevelGenerator<Rules ...>::applyer(Map *map){
    std::cout<<"applyer\n";
    Rule rule;
    std::cout<<"rule obj\n";
    rule.apply(map);
    std::cout<<"rue appled\n";
};


template <typename ... Rules>
void LevelGenerator<Rules ...>::applyRules(Map *map){
    std::cout<<"apply rules\n";
    (Rules::apply(map), ...);
    //(applyer<Rules>(map), ...);
};
