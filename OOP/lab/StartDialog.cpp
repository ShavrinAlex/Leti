#include <iostream>
#include "StartDialog.h"

//initialization
StartDialog::StartDialog(){
    std::cout<<"Введите размеры поля (n на m клеток):\n";
    std::cout<<"Высота: ";
    std::cin>>start_height;
    std::cout<<"Ширина: ";
    std::cin>>start_width;
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
