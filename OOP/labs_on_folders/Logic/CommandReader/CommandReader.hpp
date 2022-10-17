#pragma once
#include <SFML/Graphics.hpp>
#include "../GameElement/GameElement.hpp"

class CommandReader: public GameElement{
    public:
        //read kyboard
        void getPressedKey();
};
