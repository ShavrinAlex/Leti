#pragma once
#include "../MediatorPattern/GameElement/GameElementDescription.hpp"

class CommandReader: public GameElement<std::string>{
    public:
        //read kyboard
        void getPressedKey();
};
