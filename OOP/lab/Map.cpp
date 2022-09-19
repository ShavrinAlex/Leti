#include "Map.h"
#include <iostream>
#define WIDTH 10
#define HEIGHT 10

//initialization
Map::Map(){
    width = WIDTH;
    height = HEIGHT;
    map = create_map();
};
Map::Map(int width, int height){
    this->width = width;
    this->height = height;
    map = create_map();
};

//create map
CellMatrix* Map::create_map(){
    map = new CellMatrix;
    map->reserve(height);
    for (int i = 0; i < height; i++){
        std::vector <Cell*> *line = new std::vector <Cell*>[width];
        map->push_back(line);
        for (int j = 0; j < width; j++){
            //create cell
            Cell *cl = new Cell(j, i, 50.0, false);
            map->back()->push_back(cl);
        }
    }
    std::cout<<"map was created\n";
    return map;
};

//draw map
void Map::draw(sf::RenderWindow *window){
    for (auto row: *map){
        for (auto cell: *row){
            cell->draw(window);
        }
    }
};

//destruction
Map::~Map(){
    for (int i = 0; i < height; i++){
        map[i].clear();
    }
};
