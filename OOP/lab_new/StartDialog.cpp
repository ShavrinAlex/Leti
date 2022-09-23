#include "StartDialog.hpp"
#include <iostream>
#define BASE_HEIGHT 5
#define BASE_WIDTH 5

//initialization
StartDialog::StartDialog(){
    is_size_set = false;

    executor();
    
    if (is_size_set == false){
        map_height = BASE_HEIGHT;
        map_width = BASE_WIDTH;
    }
};

//map
bool StartDialog::isSizeSet(){
    return is_size_set;
};
int StartDialog::getHeight(){
    return map_height;
};
int StartDialog::getWidth(){
    return map_width;
};

//executor
void StartDialog::executor(){
    char map_answer;
    std::cout<<"Хотите задать свои значения поля? [y/n]: ";
    std::cin>>map_answer;
    if (map_answer == 'y'){
        std::cout<<"Введите размеры поля (n на m клеток):\n";
        std::cout<<"Высота: ";
        std::cin>>map_height;
        std::cout<<"Ширина: ";
        std::cin>>map_width;
        is_size_set = true;
    }
};
