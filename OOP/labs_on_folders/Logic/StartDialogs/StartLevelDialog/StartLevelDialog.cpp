#include "StartLevelDialog.hpp"
#include <iostream>

#define LEVEL_ONE_MAP_WIDTH 5
#define LEVEL_ONE_MAP_HEIGHT 5
#define LEVEL_TWO_MAP_WIDTH 8
#define LEVEL_TWO_MAP_HEIGHT 8

//initialization
StartLevelDialog::StartLevelDialog(Mediator<Log*>* mediator){
    this->setMediator(mediator);
};

//user dialog
int StartLevelDialog::userDialog(){
    std::string answer;

    std::cout<<"Выберите уровень из предложенных: ";
    std::cout<<"1 - первый, 2 - второй\n";
    std::cin>>answer;

    switch(answer[0]){
        case '1':
            level = One;
            map_height = LEVEL_ONE_MAP_HEIGHT;
            map_width = LEVEL_ONE_MAP_WIDTH;
            break;
        case '2':
            level = Two;
            map_height = LEVEL_TWO_MAP_HEIGHT;
            map_width = LEVEL_TWO_MAP_WIDTH;
            break;
        default:
            return -1;
    }
    return 0;
};

//executor
void StartLevelDialog::executor(){
    while (this->userDialog() != 0){
        //logging
        Log* log = new Log(Errors, "Error!!! Entered invalid map sizes");
        this->mediator->send(log);
        delete log;
        std::cout<<"Вы ввели недопустимый размер поля. Повторите снова\n";
    }
};

//parametrs
int StartLevelDialog::getHeight(){
    return this->map_height;
};
int StartLevelDialog::getWidth(){
    return this->map_width;
};
Levels StartLevelDialog::getLevel(){
    return this->level;
};
