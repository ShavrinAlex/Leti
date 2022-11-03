#include "StartMapSizeDialog.hpp"
#include <iostream>
#define MIN_SIZE 5
#define START_MAP_WIDTH 5
#define START_MAP_HEIGHT 5

//initialization
StartMapSizeDialog::StartMapSizeDialog(Mediator<Log*>* mediator){
    this->setMediator(mediator);
    this->is_size_set = false;
};

//user dialog
int StartMapSizeDialog::userDialog(){
    char map_answer;
    int map_height, map_width;

    std::cout<<"Хотите задать свои значения поля (вместо "<<START_MAP_WIDTH<<" на "<<START_MAP_HEIGHT<<")? [y]: ";
    std::cin>>map_answer;

    if (map_answer == 'y'){
        std::cout<<"Минимальный размер поля: "<<MIN_SIZE<<" на "<<MIN_SIZE<<" клеток\n";
        std::cout<<"Высота: ";
        std::cin>>map_height;
        std::cout<<"Ширина: ";
        std::cin>>map_width;

        if (map_height < MIN_SIZE || map_width < MIN_SIZE){
            return -1;
        }
        
        this->map_height = map_height;
        this->map_width = map_width;
        this->is_size_set = true;
    }
    return 0;
};

//executor
void StartMapSizeDialog::executor(){
    while (this->userDialog() != 0){
        //logging
        Log* log = new Log(Errors, "Error!!! Entered invalid map sizes");
        this->mediator->send(log);
        delete log;
        std::cout<<"Вы ввели недопустимый размер поля. Повторите снова\n";
    }

    //set default size
    if (this->is_size_set == false){
        this->map_width = START_MAP_WIDTH;
        this->map_height = START_MAP_HEIGHT;
    }
};

//map
int StartMapSizeDialog::getHeight(){
    return this->map_height;
};
int StartMapSizeDialog::getWidth(){
    return this->map_width;
};
