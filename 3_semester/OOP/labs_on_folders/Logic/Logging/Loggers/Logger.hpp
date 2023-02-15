#pragma once
#include "../Log/Log.hpp"

class Logger{
    public:
        //print log
        virtual void print(Log* log) = 0;

        //destruction
        virtual ~Logger(){};
};
