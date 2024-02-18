#pragma once
#include "../../Logging/Loggers/ConsoleLogger/ConsoleLogger.hpp"
#include "../../Logging/Loggers/FileLogger/FileLogger.hpp"
#include "../../Utility/Enumerations.hpp"
#include <vector>

typedef std::vector <LogCout> OutputStreams;

class LogController{
    private:
        ConsoleLogger* console_logger;
        FileLogger* file_logger;

        LogLevels level;
        OutputStreams log_cout;
    public:
        //initialization
        LogController();

        //set parameters
        void setLevel(LogLevels level);
        void addStream(LogCout stream);

        //remove paremetrs
        void removeStream(LogCout stream);

        //handle log message
        void handleLog(Log* log);

        //destruction
        ~LogController();
};
