#include <iostream>
#include "StartDialog.h"
#define BASE_HEIGHT 5
#define BASE_WIDTH 5
#define BASE_POSITION_X 1
#define BASE_POSITION_Y 1

//initialization
StartDialog::StartDialog(){
    //если хочет менять изменить, если нет уствновить базовые значения
    is_size_set = false;
    is_player_position_set = false;

    executor();
    
    if (is_size_set == false){
        start_height = BASE_HEIGHT;
        start_width = BASE_WIDTH;
    }
    if (is_player_position_set == false){
        player_position.x = BASE_POSITION_X;
        player_position.y = BASE_POSITION_Y;
    }
    
};

//executor
void StartDialog::executor(){
    char map_answer;
    char player_answer;
    std::cout<<"Хотите задать свои значения поля? [y/n]: ";
    std::cin>>map_answer;
    if (map_answer == 'y'){
        std::cout<<"Введите размеры поля (n на m клеток):\n";
        std::cout<<"Высота: ";
        std::cin>>start_height;
        std::cout<<"Ширина: ";
        std::cin>>start_width;
        is_size_set = true;
    }
    std::cout<<"Хотите задать свои значения начальной позиции игрока? [y/n]: ";
    std::cin>>player_answer;
    if (player_answer == 'y'){
        std::cout<<"Координата х: ";
        std::cin>>player_position.x;
        std::cout<<"Координата у: ";
        std::cin>>player_position.y;
        is_player_position_set = true;
    }
};

//map
bool StartDialog::isSizeSet(){
    return is_size_set;
};
int StartDialog::getHeight(){
    return start_height;
};
int StartDialog::getWidth(){
    return start_width;
};

//player
bool StartDialog::isPlayerPositionSet(){
    return is_player_position_set;
};
Position StartDialog::getPlayerPosition(){
    return player_position;
};
