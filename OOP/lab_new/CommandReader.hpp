#include <SFML/Graphics.hpp>

enum Direction{Right, Left, Up, Down};

class CommandReader{
    public:
        //read kyboard
        Direction getPressedKey();
};
