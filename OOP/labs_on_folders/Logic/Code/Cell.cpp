#include "../Headlines/Cell.hpp"
#include <iostream>

//initialization
Cell::Cell(bool is_wall, bool is_here_player){
    //std::cout<<this<<" constr\n";
    this->is_wall = is_wall;
    this->is_here_player = is_here_player;
    this->event = nullptr;
};

//coping
Cell::Cell(const Cell& obj){
    //std::cout<<this<<" constr copy\n";
    this->is_wall = obj.is_wall;
    this->is_here_player = obj.is_here_player;
};
//assignment
Cell& Cell::operator = (const Cell& obj){
    //std::cout<<this<<" oper prisv\n";
    if (this != &obj){
        this->is_wall = obj.is_wall;
        this->is_here_player = obj.is_here_player;
    }
    return *this;
};

//move
Cell::Cell(Cell&& obj){
    //std::cout<<this<<" constr peremesh\n";
    std::swap(this->is_wall, obj.is_wall);
    std::swap(this->is_here_player, obj.is_here_player);
};
Cell& Cell::operator = (Cell&& obj){
    //std::cout<<this<<" oper peremesh\n";
    if (this != &obj){
        std::swap(this->is_wall, obj.is_wall);
        std::swap(this->is_here_player, obj.is_here_player);
    }
    return *this;
};

//set event
void Cell::setEvent(Event* event){
    this->event = event;
};
void Cell::removeEvent(){
    delete this->event;
    this->event = nullptr;
};

//get event
Event* Cell::getEvent(){
    return this->event;
};

//check is wall
bool Cell::isWall(){
    return this->is_wall;
};

//set and remove wall
void Cell::setWall(){
    this->is_wall = true;

    //notify observer
    this->notify();
};
void Cell::removeWall(){
    this->is_wall = false;

    //notify observer
    this->notify();
};

//check player is here
bool Cell::isHerePlayer(){
    return this->is_here_player;
};

//set and remove player
void Cell::setPlayer(){
    this->is_here_player = true;
    if (this->event != nullptr){
        this->event->execute();
        this->removeEvent();
    }

    //notify observer
    this->notify();
};
void Cell::removePlayer(){
    this->is_here_player = false;
    
    //notify observer
    this->notify();
}

Cell::~Cell(){
    this->event = nullptr;
};
