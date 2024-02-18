#include "EventOnMap.hpp"

//initialization
EventOnMap::EventOnMap(Map* map){
    this->map = map;
};

//destruction
EventOnMap::~EventOnMap(){
    this->map = nullptr;
};