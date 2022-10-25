#include "StartDialog.hpp"
#include <iostream>
#define MIN_SIZE 5
#define START_MAP_WIDTH 5
#define START_MAP_HEIGHT 5

//initialization
StartDialog::StartDialog(){
    this->is_size_set = false;

    while (executor() != 0){
        std::cout<<"Вы ввели недопустимый размер поля. Повторите снова\n";
    }

    if (this->is_size_set == false){
        this->map_width = START_MAP_WIDTH;
        this->map_height = START_MAP_HEIGHT;
    }
};

//map
int StartDialog::getHeight(){
    return this->map_height;
};
int StartDialog::getWidth(){
    return this->map_width;
};
bool StartDialog::getIsSizeSet(){
    return is_size_set;
};

//executor
int StartDialog::executor(){
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
