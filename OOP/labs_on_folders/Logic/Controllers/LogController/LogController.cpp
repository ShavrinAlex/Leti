#include "LogController.hpp"

//convert user requests
void LogController::convertLevels(std::string user_levels){
    std::cout<<user_levels<<'\n';
    std::cout<<user_levels.size()<<'\n';
    for (int i = 0; i < user_levels.size(); i++){
        switch(user_levels[i]){
            case '0':
                std::cout<<"case 0\n";
                this->levels.emplace_back(Errors);
                break;
            case '1':
                std::cout<<"case 1\n";
                this->levels.emplace_back(Processes);
                break;
            case '2':
                std::cout<<"case 2\n";
                this->levels.emplace_back(GameStates);
                break;
        }
    }
    std::cout<<"levels:\n";
    for (size_t i = 0; i < this->levels.size(); i++){
        std::cout<<"level "<<this->levels.at(i);
    }
    std::cout<<"\n";
};

void LogController::convertStreams(std::string user_streams){
    for (int i = 0; i < user_streams.size(); i++){
        switch(user_streams[i]){
            case '0':
                this->log_cout.emplace_back(Console);
                break;
            case '1':
                this->log_cout.emplace_back(File);
                break;
        }
    }
    std::cout<<"streams:\n";
    for (size_t i = 0; i < this->log_cout.size(); i++){
        std::cout<<"streams "<<this->log_cout.at(i);
    }
    std::cout<<"\n";
};

//user dialog
int LogController::userDialog(bool& f1, bool& f2){
    char user_answer1;
    std::cout<<"Хотите задать уровни логирования? (По умолчанию все: errors) [y]: ";
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
    std::cout<<"Хотите задать куда выводить логи? (По умолчанию все: file) [y]: ";
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

    if (is_levels_set == false && is_streams_set == false){
        //this->levels.emplace_back(GameStates);
        //this->levels.emplace_back(Processes);
        this->levels.emplace_back(Errors);
        //this->log_cout.emplace_back(Console);
        this->log_cout.emplace_back(File);
    }
    /*
    if (is_levels_set == false || this->levels.empty()){
        this->convertLevels("errors;game_states;processes");
    }
    if (is_streams_set == false || this->log_cout.empty()){
        this->convertStreams("console;file");
    }
    */
};

//initialization
LogController::LogController(){
    this->console_logger = new ConsoleLogger();
    this->file_logger = new FileLogger("Logs.txt");
    //this->levels.emplace_back(GameStates);
    //this->levels.emplace_back(Processes);
    //this->levels.emplace_back(Errors);
    //this->log_cout.emplace_back(Console);
    //this->log_cout.emplace_back(File);
    this->setParametrs();
};

//set handle log levels
void LogController::setHandleLogLevels(Levels levels){
    this->levels.clear();
    this->levels = levels;
};

//set output streams
void LogController::setOutputStreams(OutputStreams cout){
    this->log_cout.clear();
    this->log_cout = cout;
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
