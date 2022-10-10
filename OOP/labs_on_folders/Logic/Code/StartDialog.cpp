#include "../Headlines/StartDialog.hpp"
#include <iostream>
#define BASE_HEIGHT 5
#define BASE_WIDTH 5

//initialization
StartDialog::StartDialog(){
    this->is_size_set = false;

    while (executor() != 0){
        std::cout<<"Вы ввели недопустимый размер поля. Повторите снова\n";
    }
    
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
int StartDialog::executor(){
    char map_answer;
    int map_height, map_width;
    std::cout<<"Хотите задать свои значения поля? [y/n]: ";
    std::cin>>map_answer;
    if (map_answer == 'y'){
        std::cout<<"Минимальный размер поля: 3 на 3 клеток\n";
        std::cout<<"Введите размеры поля (n на m клеток):\n";
        std::cout<<"Высота: ";
        std::cin>>map_height;
        std::cout<<"Ширина: ";
        std::cin>>map_width;
        if (map_height < 3 || map_width < 3){
            return -1;
        }
        this->map_height = map_height;
        this->map_width = map_width;
        this->is_size_set = true;
    }
    return 0;
};
