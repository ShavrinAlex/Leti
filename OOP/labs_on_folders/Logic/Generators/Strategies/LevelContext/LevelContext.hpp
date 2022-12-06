#include "../LevelStrategy.hpp"

class LevelContext{
    private:
        LevelStrategy* strategy;
    public:
        //initialization
        LevelContext();

        //set strategy
        void setStrategy(LevelStrategy* strategy);

        //create level
        Map* createLevel();

        //destruction
        ~LevelContext();
};