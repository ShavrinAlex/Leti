#pragma once
#include <iostream>
#include "../../Utility/Enumerations.hpp"

class Log{
    private:
        LogLevels level;
        std::string log_message;
    public:
        //initialization
        Log(LogLevels level, std::string log_message);

        //get log level
        LogLevels getLevel();

        //get log message
        std::string getLogMessage();

        //reloading output into a stream
        friend std::ostream& operator << (std::ostream& out, const Log& log);
};
