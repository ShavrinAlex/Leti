#include "LogMediator.hpp"
#include <iostream>
//initialization
LogMediator::LogMediator(LogController* log_controller){
    this->log_controller = log_controller;
};

//send log
void LogMediator::send(Log* log){
    this->log_controller->handleLog(log);
};

//destruction
LogMediator::~LogMediator(){
    this->log_controller = nullptr;
};
