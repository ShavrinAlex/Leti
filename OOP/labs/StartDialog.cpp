#include "StartDialog.hpp"
#include <iostream>
#define BASE_HEIGHT 5
#define BASE_WIDTH 5

//initialization
StartDialog::StartDialog(){
    this->is_size_set = false;

    executor();
    
    if (this->is_size_set == false){
        this->map_height = BASE_HEIGHT;
        this->map_width = BASE_WIDTH;
    }
};

//map
int StartDialog::getHeight(){
    return this->map_height;
};
int StartDialog::getWidth(){
    return this->map_width;
};

//executor
void StartDialog::executor(){
    char map_answer;
    std::cout<<"Хотите задать свои значения поля? [y/n]: ";
    std::cin>>map_answer;
    if (map_answer == 'y'){
        std::cout<<"Введите размеры поля (n на m клеток):\n";
        std::cout<<"Высота: ";
        std::cin>>this->map_height;
        std::cout<<"Ширина: ";
        std::cin>>this->map_width;
        this->is_size_set = true;
    }
};
