#include "LogController.hpp"
#include "../../StartDialogs/StartLogParametrsDialog/StartLogParametrsDialog.hpp"

//initialization
LogController::LogController(){
    this->console_logger = new ConsoleLogger();
    this->file_logger = new FileLogger("Logs.txt");

    StartLogParametrDialog start_log_parametrs_dialog = StartLogParametrDialog(this);
    start_log_parametrs_dialog.executor();
};

//add parameters
void LogController::setLevel(LogLevels level){
    this->level = level;
};
void LogController::addStream(LogCout stream){
    bool check = false;
    for (size_t i = 0; i < this->log_cout.size(); i++){
        if (this->log_cout[i] == stream){
            check = true;
        }
    }
    if (check == false){
        this->log_cout.emplace_back(stream);
    }
};

//remove paremetrs
void LogController::removeStream(LogCout stream){
    for (size_t i = 0; i < this->log_cout.size(); i++){
        if (this->log_cout[i] == stream){
            auto iter = this->log_cout.begin();
            this->log_cout.erase(iter + i);
        }
    }
};

//handle log message
void LogController::handleLog(Log* log){
    //checking if this log level is tracked
    if (this->level >= log->getLevel()){
        //cout log in all streams
        for (size_t i = 0; i < this->log_cout.size(); i++){
            switch (log_cout[i]){
                case Console:
                    this->console_logger->print(log);
                    break;
                case File:
                    this->file_logger->print(log);
                    break;
            }
        }
    }
};

//destruction
LogController::~LogController(){
    delete this->console_logger;
    delete this->file_logger;
};
