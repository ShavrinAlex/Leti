#pragma once
#include "../Logger.hpp"
#include <fstream>

class FileLogger: public Logger{
    private:
        std::ofstream log_file;
    public:
        //initialization
        FileLogger(std::string log_file_name);

        //print log
        void print(Log* log) override;

        //destruction
        ~FileLogger();
};
