#include "Position.h"

class App{
    private:
        int map_height;
        int map_width;
        Position player_position;
    public:
        //player
        void setPlayerPosition(Position pp);

        //map
        void setMapSize(int h, int w);

        //executor main loop
        int executor();
};
