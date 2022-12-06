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
    Rule rule;
    rule.apply(map);
};


template <typename ... Rules>
void LevelGenerator<Rules ...>::applyRules(Map *map){
    (applyer<Rules>(map), ...);
};
