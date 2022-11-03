#include "../../MediatorPattern/GameElement/GameElementDescription.hpp"
#include "../../Logging/Log/Log.hpp"

class StartMapSizeDialog: public GameElement<Log*>{
    private:
        int map_height;
        int map_width;
        bool is_size_set;

        //user dialog
        int userDialog();
    public:
        //initialization
        StartMapSizeDialog(Mediator<Log*>* mediator);

        //executor
        void executor();

        //get map parmetrs
        int getHeight();
        int getWidth();
};
