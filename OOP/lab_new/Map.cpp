#include "Map.hpp"
#define WIDTH 5
#define HEIGHT 5
#define START_POSITION {0, 0}

//create map
void Map::createMap(CellMatrix& map){
    map.reserve(height);
    for (int y = 0; y < height; y++){
        map.emplace_back(std::vector <Cell*>());
        map.at(y).reserve(width);
        for (int x = 0; x < width; x++){
            //create cell
            bool is_here_player = false;
            bool is_wall = false;
            if (player_position.x == x && player_position.y == y){
                is_here_player = true;
            }
            if (rand() % 10 > 7){
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
    player_position = (Position)START_POSITION;
    createMap(map);
};
Map::Map(int width, int height){
    this->width = width;
    this->height = height;
    player_position = (Position)START_POSITION;
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
void Map::setPlayerPosition(Position* next_player_position){
    //convert player position
    if (next_player_position->x >= width){
        next_player_position->x -= width;        
    }
    if (next_player_position->x < 0){
        next_player_position->x += width;        
    }
    if (next_player_position->y >= height){
        next_player_position->y -= height;        
    }
    if (next_player_position->y < 0){
        next_player_position->y += height;        
    }
    if (map.at(next_player_position->y).at(next_player_position->x)->isWall()){
        return;
    } else{
        map.at(player_position.y).at(player_position.x)->setPlayer(false);
        //set new position
        player_position.x = next_player_position->x;
        player_position.y = next_player_position->y;
        //std::cout<<player_position.x<<' '<<player_position.y<<'\n';
        //reaction on hero
        map.at(player_position.y).at(player_position.x)->setPlayer(true);
        delete next_player_position;
    }
};

//get player position
Position* Map::getPlayerPosition(){
    return &player_position;
};

//calculate next player position
Position* Map::calculateNextPlayerPosition(int speed, Direction direction){
    int dx = 0;
    int dy = 0;
    switch (direction){
        case Right:
            dx = speed;
            break;
        case Left:
            dx = -speed;
            break;
        case Up:
            dy = -speed;
            break;
        case Down:
            dy = speed;
            break;
    }
    Position* next_player_position = new Position();
    next_player_position->x = player_position.x + dx;
    next_player_position->y = player_position.y + dy;
    return next_player_position;
};
