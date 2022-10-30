#include "LogController.hpp"

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

//convert user requests
int LogController::convertLevel(char user_level){
    switch(user_level){
        case '2':
            this->setLevel(GameStates);
            break;
        case '1':
            this->setLevel(Processes);
            break;
        case '0':
            this->setLevel(Errors);
            break;
        default:
            return -1;
    }
    return 0;
};
int LogController::convertStreams(std::string user_streams){
    for (size_t i = 0; i < user_streams.size(); i++){
        switch(user_streams[i]){
            case '0':
                this->addStream(Console);
                break;
            case '1':
                this->addStream(File);
                break;
            default:
                return -1;
        }
    }
    return 0;
};

//user dialog
int LogController::userDialog(bool& f1, bool& f2){
    char user_answer1;
    std::cout<<"Хотите задать свой уровень логирования? (По умолчанию: errors) [y]: ";
    std::cin>>user_answer1;

    if (user_answer1 == 'y'){
        char user_level;
        std::cout<<"0 - errors, 1 - processes, 2 - game_states\n";
        std::cin>>user_level;
        if (this->convertLevel(user_level) == 0){
            f1 = true;
        } else{
            return -1;    
        }
    }
    char user_answer2;
    std::cout<<"Хотите задать куда выводить логи? (По умолчанию: console) [y]: ";
    std::cin>>user_answer2;

    if (user_answer2 == 'y'){
        std::string user_streams;
        std::cout<<"0 - console, 1 - file\n";
        std::cout<<"Вводите потоки вывода логов по следующему образцу: <index><index>\n";
        std::cin>>user_streams;
        if (this->convertStreams(user_streams) == 0){
            f2 = true;
        } else{
            return -1;
        }
    }

    return 0;
};

//set log parameters
void LogController::setParametrs(){
    bool is_levels_set = false;
    bool is_streams_set = false;

    while (userDialog(is_levels_set, is_streams_set) != 0){
        std::cout<<"Вы ввели значения неправильно. Повторите снова\n";
    }
    
    std::cout<<"По ходу программы можно задавать параметры логирования с помощью клавиатуры.\n";
    std::cout<<"Установить уровень логирования:\n0 - errors\t1 - processes\t2 - game states\n";
    std::cout<<"Добавить поток логирования:\n6 - console\t7 - file\n";
    std::cout<<"Удалить поток логирования:\nF6 - console\tF7 - processes\n";
    
    if (is_levels_set == false){
        this->setLevel(Errors);
    }
    if (is_streams_set == false){
        this->log_cout.emplace_back(Console);
        //this->log_cout.emplace_back(File);
    }
};

//initialization
LogController::LogController(){
    this->console_logger = new ConsoleLogger();
    this->file_logger = new FileLogger("Logs.txt");

    this->setParametrs();
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
    bool tracked = false;

    //checking if this log level is tracked
    if (this->level >= log->getLevel()){
        tracked = true;
    }

    if (tracked){
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
