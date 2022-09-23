#include "Map.hpp"
#define WIDTH 5
#define HEIGHT 5

//create map
void Map::createMap(CellMatrix& map){
    map.reserve(height);
    for (int y = 0; y < height; y++){
        map.at(y).reserve(width);
        for (int x = 0; x < width; x++){
            //create cell
            bool is_here_player = false;
            bool is_wall = false;
            if (player_position.x == x && player_position.y == y){
                is_here_player = true;
            }
            if (x == 3 && y == 3){
                is_wall = true;
            }
            Cell *cl = new Cell(is_wall, is_here_player);
            map.back().push_back(cl);
        }
    }
};

//initialization
Map::Map(){
    this->width = WIDTH;
    this->height = HEIGHT;
    createMap(map);
};
Map::Map(int width, int height){
    this->width = width;
    this->height = height;
    createMap(map);
};

//get size
int Map::getHeight(){
    return height;
};
int Map::getWidth(){
    return width;
};

//get cell
Cell* Map::getCell(int pos_x, int pos_y){
    return map.at(pos_y).at(pos_x);
};

//set player position
void Map::setPlayerPosition(Position next_player_position){
    //convert player position
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

    if (map.at(next_player_position.y).at(next_player_position.x)->isWall()){
        return;
    } else{
        map.at(player_position.y).at(player_position.x)->setPlayer(false);
        //set new position
        player_position.x = next_player_position.x;
        player_position.y = next_player_position.y;
        //reaction on hero
        map.at(next_player_position.y).at(next_player_position.x)->setPlayer(true);
    }
};

//get player position
Position Map::getPlayerPosition(){
    return player_position;
};