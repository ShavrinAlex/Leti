#pragma once
#include "../../Map/Map.hpp"

class LevelStrategy{
    public:
        virtual Map* generateLevel() = 0;
        virtual ~LevelStrategy(){};
};
