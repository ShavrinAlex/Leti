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

        //convert user requests
        int convertLevel(char user_level);
        int convertStreams(std::string user_streams);

        //user dialog
        int userDialog(bool& f1, bool& f2);

        //set log parameters
        void setParametrs();
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
