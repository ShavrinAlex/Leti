#pragma once
#include "../Logger.hpp"

class ConsoleLogger: public Logger{
    public:
        //print log
        void print(Log* log) override;
};
