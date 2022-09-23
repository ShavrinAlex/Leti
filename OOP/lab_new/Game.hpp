#include "RenderWindow.hpp"

class Game{
    private:
        int map_width;
        int map_height;
        RenderWindow window;
    public:
        //initialization
        Game(RenderWindow& window, int map_width, int map_height);

        //game
        int game_executor();
};
