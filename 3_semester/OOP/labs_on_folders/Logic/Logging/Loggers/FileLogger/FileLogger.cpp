#include "FileLogger.hpp"

//initialization
FileLogger::FileLogger(std::string log_file_name){
    this->log_file.open(log_file_name, std::ios_base::out | std::ios_base::trunc);
};

//print log
void FileLogger::print(Log* log){
    log_file<<(*log);
};

//destruction
FileLogger::~FileLogger(){
    this->log_file.close();
};
