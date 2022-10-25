#include "../MediatorPattern/GameElement/GameElementDescription.hpp"
#include "../Logging/Log/Log.hpp"

class StartDialog: public GameElement<Log*>{
    private:
        int map_height;
        int map_width;
        bool is_size_set;
    public:
        //initialization
        StartDialog(Mediator<Log*>* mediator);

        //map
        int getHeight();
        int getWidth();
        bool getIsSizeSet();

        //executor
        int executor();
};
