#include "StartLogParametrsDialog.hpp"
#include <iostream>

//convert user requests
int StartLogParametrDialog::convertLevel(char user_level){
    switch(user_level){
        case '2':
            this->log_controller->setLevel(GameStates);
            break;
        case '1':
            this->log_controller->setLevel(Processes);
            break;
        case '0':
            this->log_controller->setLevel(Errors);
            break;
        default:
            return -1;
    }
    return 0;
};
int StartLogParametrDialog::convertStreams(std::string user_streams){
    for (size_t i = 0; i < user_streams.size(); i++){
        switch(user_streams[i]){
            case '0':
                this->log_controller->addStream(Console);
                break;
            case '1':
                this->log_controller->addStream(File);
                break;
            default:
                return -1;
        }
    }
    return 0;
};

//initialization
StartLogParametrDialog::StartLogParametrDialog(LogController* log_controller){
    this->log_controller = log_controller;
    this->is_levels_set = false;
    this->is_streams_set = false;
};

//user dialog
int StartLogParametrDialog::userDialog(){
    char user_answer1;
    std::cout<<"Хотите задать свой уровень логирования? (По умолчанию: errors) [y]: ";
    std::cin>>user_answer1;

    if (user_answer1 == 'y'){
        char user_level;
        std::cout<<"0 - errors, 1 - processes, 2 - game_states\n";
        std::cin>>user_level;
        if (this->convertLevel(user_level) == 0){
            this->is_levels_set = true;
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
            this->is_streams_set = true;
        } else{
            return -1;
        }
    }

    return 0;
};

//executor
void StartLogParametrDialog::executor(){
    //dialog with user
    while (this->userDialog() != 0){
        std::cout<<"Вы ввели значения неправильно. Повторите снова\n";
    }
    /*
    //instruction how set parametrs in runtime
    std::cout<<"По ходу программы можно задавать параметры логирования с помощью клавиатуры.\n";
    std::cout<<"Установить уровень логирования:\n0 - errors\t1 - processes\t2 - game states\n";
    std::cout<<"Добавить поток логирования:\n6 - console\t7 - file\n";
    std::cout<<"Удалить поток логирования:\nF6 - console\tF7 - processes\n";
    */
    //set default parametrs
    if (this->is_levels_set == false){
        this->log_controller->setLevel(Errors);
    }
    if (this->is_streams_set == false){
        this->log_controller->addStream(Console);
        //this->log_controller->addStream(File);
    }
};

 //destruction
StartLogParametrDialog::~StartLogParametrDialog(){
    this->log_controller = nullptr;
};
