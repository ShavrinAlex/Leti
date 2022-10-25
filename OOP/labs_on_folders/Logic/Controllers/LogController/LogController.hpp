#pragma once
#include "../../Logging/Loggers/ConsoleLogger/ConsoleLogger.hpp"
#include "../../Logging/Loggers/FileLogger/FileLogger.hpp"
#include "../../Utility/Enumerations.hpp"
#include <vector>

typedef std::vector <LogLevels> Levels;
typedef std::vector <LogCout> OutputStreams;

class LogController{
    private:
        ConsoleLogger* console_logger;
        FileLogger* file_logger;

        Levels levels;

        OutputStreams log_cout;

        //convert user requests
        void convertLevels(std::string user_levels);
        void convertStreams(std::string user_streams);

        //user dialog
        int userDialog(bool& f1, bool& f2);
    public:
        //initialization
        LogController();

        //set log parameters
        void setParametrs();

        //handle log message
        void handleLog(Log* log);

        //destruction
        ~LogController();
};
