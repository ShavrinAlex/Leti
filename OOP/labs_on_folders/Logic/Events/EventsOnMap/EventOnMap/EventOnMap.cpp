#include "EventOnMap.hpp"

//initialization
EventOnMap::EventOnMap(Map* map, Generator* generator){
    this->map = map;
    this->generator = generator;
};

//destruction
EventOnMap::~EventOnMap(){
    this->map = nullptr;
};