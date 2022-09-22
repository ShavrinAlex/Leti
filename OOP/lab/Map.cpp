#include "Map.h"
#include <iostream>
#define WIDTH 5
#define HEIGHT 5
#define SIDE 98.f

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

//get size
int Map::getHeight(){
    return height;
};
int Map::getWidth(){
    return width;
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
            bool hero_here = false;
            bool is_busy = false;
            if (player_position.x == j && player_position.y == i){
                hero_here = true;
            }
            if (i == 3 && j == 3){
                is_busy = true;
            }
            Cell *cl = new Cell(SIDE, is_busy, hero_here);
            map->back()->push_back(cl);
        }
    }
    return map;
};

//get cell
Cell* Map::getCell(int pos_x, int pos_y){
    return map->at(pos_y)->at(pos_x);
};

//get map
CellMatrix* Map::get_map(){
    return map;
};

//set player position
void Map::setPlayerPosition(Position next_player_position){
    if (next_player_position.x >= width){
        next_player_position.x -= width;        
    }
    if (next_player_position.x < 0){
        next_player_position.x += width;        
    }
    if (next_player_position.y >= height){
        next_player_position.y -= height;        
    }
    if (next_player_position.y < 0){
        next_player_position.y += height;        
    }
    this->player_position.x = next_player_position.x;
    this->player_position.y = next_player_position.y;
    map->at(next_player_position.y)->at(next_player_position.x)->setHero(true);

}

//get player position
Position Map::getPlayerPosition(){
    return player_position;
};

//move player on next cell
void Map::movePlayer(Position next_player_position){
    //loop map
    if (next_player_position.x >= width){
        next_player_position.x -= width;        
    }
    if (next_player_position.x < 0){
        next_player_position.x += width;        
    }
    if (next_player_position.y >= height){
        next_player_position.y -= height;        
    }
    if (next_player_position.y < 0){
        next_player_position.y += height;        
    }
    if (map->at(next_player_position.y)->at(next_player_position.x)->is_busy_cell()){
        return;
    } else{
        //change cell without hero
        //std::cout<<"move\n";
        map->at(player_position.y)->at(player_position.x)->setHero(false);
        
        //set new position
        player_position.x = next_player_position.x;
        player_position.y = next_player_position.y;
        //reaction on hero
        map->at(next_player_position.y)->at(next_player_position.x)->setHero(true);
    }
};

//update
void Map::update(){
    for (auto row: *map){
        for (auto cell: *row){
            cell->update();
        }
    }
};

//destruction
Map::~Map(){
    for (int i = 0; i < height; i++){
        map[i].clear();
    }
};

/*
//draw map
void Map::draw(sf::RenderWindow *window){
    for (auto row: *map){
        for (auto cell: *row){
            cell->draw(window);
        }
    }
};
*/
