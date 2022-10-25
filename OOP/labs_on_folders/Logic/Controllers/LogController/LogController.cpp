#include "LogController.hpp"
/*
//convert user requests
void LogController::convertLevels(std::string user_levels){
    std::string separator = ";";
    size_t start_position = 0;
    std::cout<<user_levels;
    size_t found = user_levels.find(separator, start_position);
    while (found != std::string::npos){
        std::string level = user_levels.substr(start_position, found-1);
        if (level == "errors"){
            this->levels.emplace_back(Errors);
        }
        if (level == "game_states"){
            this->levels.emplace_back(GameStates);
        }
        if (level == "processes"){
            this->levels.emplace_back(Processes);
        }
        start_position = found + 1;
    }
    std::cout<<"levels:\n";
    for (size_t i = 0; i < this->levels.size(); i++){
        std::cout<<"level ";
    }
};
void LogController::convertStreams(std::string user_streams){
    std::string separator = ";";
    size_t start_position = 0;
    size_t found = user_streams.find(separator, start_position);
    while (found != std::string::npos){
        std::string stream = user_streams.substr(start_position, found-1);
        if (stream == "console"){
            this->log_cout.emplace_back(Console);
        }
        if (stream == "file"){
            this->log_cout.emplace_back(File);
        }
        start_position = found + 1;
    }
};

//set log parameters
void LogController::setParametrs(){
    bool is_levels_set = false;
    bool is_streams_set = false;

    char user_answer;
    std::cout<<"Хотите задать уровни логирования? (По умолчанию все: errors, game_states, processes) [y]: ";
    std::cin>>user_answer;

    if (user_answer == 'y'){
        std::string user_levels;
        std::cout<<"Вводите уровни по следующему образцу: <level>;<level>\n";
        std::cin>>user_levels;
        std::cout<<"levels was read\n";
        this->convertLevels(user_levels);
        is_levels_set = true;
    }

    std::cout<<"Хотите задать куда выводить логи? (По умолчанию все: console, file) [y]: ";
    std::cin>>user_answer;

    if (user_answer == 'y'){
        std::string user_streams;
        std::cout<<"Вводите потоки вывода логов по следующему образцу: <stream>;<stream>\n";
        std::cin>>user_streams;
        this->convertStreams(user_streams);
        is_streams_set = true;
    }

    if (is_levels_set == false || this->levels.empty()){
        this->convertLevels("errors;game_states;processes");
    }
    if (is_streams_set == false || this->log_cout.empty()){
        this->convertStreams("console;file");
    }
};
*/
//initialization
LogController::LogController(){
    this->console_logger = new ConsoleLogger();
    this->file_logger = new FileLogger("Logs.txt");
    this->levels.emplace_back(GameStates);
    this->levels.emplace_back(Processes);
    this->levels.emplace_back(Errors);
    this->log_cout.emplace_back(Console);
    this->log_cout.emplace_back(File);
    //this->setParametrs();
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
