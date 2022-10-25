#include "Log.hpp"

//initialization
Log::Log(LogLevels level, std::string log_message){
    this->level = level;
    this->log_message = "LogLevel: " + std::to_string(this->level) + " ; Message: " + log_message;
};

//get log level
LogLevels Log::getLevel(){
    return this->level;
};

//get log message
std::string Log::getLogMessage(){
    return this->log_message;
};

//reloading output into a stream
std::ostream& operator << (std::ostream& out, const Log& log){
    out<<(log.log_message)<<std::endl;
    return out;
};
