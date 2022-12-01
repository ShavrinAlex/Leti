#pragma once
#include "../Utility/Enumerations.hpp"
#include "../Logging/Log/Log.hpp"
#include "../MediatorPattern/GameElement/GameElementDescription.hpp"

class Event: public GameElement<Log*>{
    public:
        EventStatus virtual execute() = 0;
        virtual ~Event(){};
};
