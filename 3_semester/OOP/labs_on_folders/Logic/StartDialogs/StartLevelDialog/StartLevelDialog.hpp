#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"
#include "../../Logging/Log/Log.hpp"

class StartLevelDialog: public GameElement<Log*>{
    private:
        int map_height;
        int map_width;
        Levels level;

        //user dialog
        int userDialog();
    public:
        //initialization
        StartLevelDialog();

        //executor
        void executor();

        //get parmetrs
        int getHeight();
        int getWidth();
        Levels getLevel();
};
