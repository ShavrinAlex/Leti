#include "../../Graphic/Headlines/GraphicArts.hpp"

class Game{
    private:
        int map_width;
        int map_height;
        GraphicArts* graphic_arts;
    public:
        //initialization
        Game();

        //game start
        int startGame();

        //destruction
        ~Game();
};
