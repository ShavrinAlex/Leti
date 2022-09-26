#include "GraphicArts.hpp"

class Game{
    private:
        int map_width;
        int map_height;
        GraphicArts* graphic_arts;
    public:
        //initialization
        Game(int map_width, int map_height);

        //game
        int game_executor();
};
