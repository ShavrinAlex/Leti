#pragma once
#include "../Mediator.hpp"
#include "../../Logging/Log/Log.hpp"
#include "../../Logging/Loggers/ConsoleLogger/ConsoleLogger.hpp"
#include "../../Logging/Loggers/FileLogger/FileLogger.hpp"
#include "../../Controllers/LogController/LogController.hpp"

class LogMediator: public Mediator<Log*>{
    private:
        LogController* log_controller;
    public:
        //initialization
        LogMediator(LogController* log_controller);

        //send log
        void send(Log* log) override;

        //destruction
        ~LogMediator();
};
