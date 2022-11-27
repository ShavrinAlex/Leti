#include "../../../Map/Map.hpp"

template <typename ... Rules>
class LevelGenerator{
public:
    void applyRules(Map *map);
};


template <typename ... Rules>
void LevelGenerator<Rules ...>::applyRules(Map *map){
    (Rules::apply(map), ...);
};
