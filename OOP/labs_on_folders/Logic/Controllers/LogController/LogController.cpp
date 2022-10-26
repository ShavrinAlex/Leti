#include "LogController.hpp"

//add parameters
void LogController::addLevel(LogLevels level){
    bool check = false;
    for (size_t i = 0; i < this->levels.size(); i++){
        if (this->levels[i] == level){
            check = true;
        }
    }
    if (check == false){
        this->levels.emplace_back(level);
    }
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
void LogController::convertLevels(std::string user_levels){
    for (size_t i = 0; i < user_levels.size(); i++){
        switch(user_levels[i]){
            case '0':
                this->addLevel(Errors);
                break;
            case '1':
                this->addLevel(Processes);
                break;
            case '2':
                this->addLevel(GameStates);
                break;
        }
    }
};
void LogController::convertStreams(std::string user_streams){
    for (size_t i = 0; i < user_streams.size(); i++){
        switch(user_streams[i]){
            case '0':
                this->addStream(Console);
                break;
            case '1':
                this->addStream(File);
                break;
        }
    }
};

//user dialog
int LogController::userDialog(bool& f1, bool& f2){
    char user_answer1;
    std::cout<<"Хотите задать уровни логирования? (По умолчанию: errors) [y]: ";
    std::cin>>user_answer1;

    if (user_answer1 == 'y'){
        std::string user_levels;
        std::cout<<"0 - errors, 1 - processes, 2 - game_states\n";
        std::cout<<"Вводите уровни по следующему образцу: <index><index>...\n";
        std::cin>>user_levels;
        this->convertLevels(user_levels);
        if (this->levels.size() == 0){
            return -1;
        }
        f1 = true;
    }
    char user_answer2;
    std::cout<<"Хотите задать куда выводить логи? (По умолчанию: console) [y]: ";
    std::cin>>user_answer2;

    if (user_answer2 == 'y'){
        std::string user_streams;
        std::cout<<"0 - console, 1 - file\n";
        std::cout<<"Вводите потоки вывода логов по следующему образцу: <index><index>\n";
        std::cin>>user_streams;
        this->convertStreams(user_streams);
        if (this->log_cout.size() == 0){
            return -1;
        }
        f2 = true;
    }

    return 0;
};

//set log parameters
void LogController::setParametrs(){
    bool is_levels_set = false;
    bool is_streams_set = false;

    while (userDialog(is_levels_set, is_streams_set) != 0){
        //logging
        Log* log = new Log(Errors, "Error!!! Attempt to set incorrect logging parameters");
        this->handleLog(log);
        delete log;

        std::cout<<"Вы ввели значения неправильно. Повторите снова\n";
    }
    
    std::cout<<"По ходу программы можно задавать параметры логирования с помощью клавиатуры.\n";
    std::cout<<"Добавить уровень логирования:\n0 - errors\t1 - processes\t2 - game states\n";
    std::cout<<"Удалить уровень логирования:\nF9 - errors\tF1 - processes\tF2 - game states\n";
    std::cout<<"Добавить поток логирования:\n6 - console\t7 - file\n";
    std::cout<<"Удалить поток логирования:\nF6 - console\tF7 - processes\tF2 - game states\n";
    
    if (is_levels_set == false){
        //this->levels.emplace_back(GameStates);
        //this->levels.emplace_back(Processes);
        this->levels.emplace_back(Errors);
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
    /*
    for (size_t i = 0; i < this->levels.size(); i++){
        std::cout<<"level = "<<this->levels.at(i)<<'\n';
    }
    for (size_t i = 0; i < this->log_cout.size(); i++){
        std::cout<<"stream = "<<this->log_cout.at(i)<<'\n';
    }
    */
};

//remove paremetrs
void LogController::removeLevel(LogLevels level){
    for (size_t i = 0; i < this->levels.size(); i++){
        if (this->levels[i] == level){
            auto iter = this->levels.begin();
            this->levels.erase(iter + i);
        }
    }
};
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
    for (size_t level_index = 0; level_index < this->levels.size(); level_index++){
        if (this->levels[level_index] == log->getLevel()){
            tracked = true;
            break;
        }
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
