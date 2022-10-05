#include "../Headlines/Map.hpp"
#define WIDTH 5
#define HEIGHT 5
#define START_POSITION {0, 0}
#include <iostream>

//create map
void Map::createMap(){
    this->map.reserve(this->height);
    for (int y = 0; y < this->height; y++){
        this->map.emplace_back(std::vector <Cell*>());
        this->map.at(y).reserve(this->width);
        for (int x = 0; x < this->width; x++){
            //create cell
            bool is_here_player = false;
            bool is_wall = false;
            if (this->player_position.x == x && this->player_position.y == y){
                is_here_player = true;
            }
            if (rand() % 10 > 7 && is_here_player == false){
                is_wall = true;
            }
            Cell *cl = new Cell(is_wall, is_here_player);
            this->map.back().push_back(cl);
        }
    }
};

//initialization
Map::Map(){
    //std::cout<<"map "<<this<<" constr\n";
    this->width = WIDTH;
    this->height = HEIGHT;
    this->player_position = (Position)START_POSITION;
    createMap();
};
Map::Map(int width, int height){
    this->width = width;
    this->height = height;
    this->player_position = (Position)START_POSITION;
    createMap();
};

//coping
Map::Map(const Map& obj){
    //std::cout<<"map "<<this<<" constr copy\n";
    this->player_position.x = obj.player_position.x;
    this->player_position.y = obj.player_position.y;
    this->width = obj.width;
    this->height = obj.height;
    for (int y = 0; y < this->height; y++){
        this->map.emplace_back(std::vector <Cell*>());
        this->map.reserve(this->width);
        for (int x = 0; x < this->width; x++){
            //copy cell
            Cell* cell = new Cell(*(obj.map.at(y).at(x)));
            this->map.back().push_back(cell);
        }
    }
};
//assignment
Map& Map::operator = (const Map& obj){
    //std::cout<<"map "<<this<<" operator prisv\n";
    if (this != &obj){
        for (auto row: this->map){
            for (auto cell: row){
                delete cell;
            }
        }
        this->player_position.x = obj.player_position.x;
        this->player_position.y = obj.player_position.y;
        this->width = obj.width;
        this->height = obj.height;
        for (int y = 0; y < this->height; y++){
            this->map.emplace_back(std::vector <Cell*>());
            this->map.reserve(this->width);
            for (int x = 0; x < this->width; x++){
                //copy cell
                Cell* cell = new Cell(*(obj.map.at(y).at(x)));
                this->map.back().push_back(cell);
            }
        }
    }
    return *this;
};

//move
Map::Map(Map&& obj){
    //std::cout<<"map "<<this<<" constr peremesh\n";
    std::swap(this->player_position.x, obj.player_position.x);
    std::swap(this->player_position.y, obj.player_position.y);
    std::swap(this->width, obj.width);
    std::swap(this->height, obj.height);
    std::swap(this->map, obj.map);
};
Map& Map::operator = (Map&& obj){
    //std::cout<<"map "<<this<<" operat peremesh\n";
    if (this != &obj){
        for (auto row: this->map){
            for (auto cell: row){
                delete cell;
            }
        }
        std::swap(this->player_position.x, obj.player_position.x);
        std::swap(this->player_position.y, obj.player_position.y);
        std::swap(this->width, obj.width);
        std::swap(this->height, obj.height);
        std::swap(this->map, obj.map);
    }
    return *this;
};

//get size
int Map::getHeight(){
    return this->height;
};
int Map::getWidth(){
    return this->width;
};

//get cell
Cell* Map::getCell(int pos_x, int pos_y){
    return this->map.at(pos_y).at(pos_x);
};

//set player position
void Map::setPlayerPosition(Position* next_player_position){
    //convert player position
    if (next_player_position->x >= this->width){
        next_player_position->x -= this->width;        
    }
    if (next_player_position->x < 0){
        next_player_position->x += this->width;        
    }
    if (next_player_position->y >= this->height){
        next_player_position->y -= this->height;        
    }
    if (next_player_position->y < 0){
        next_player_position->y += this->height;        
    }
    
    //check cell on wall
    if (map.at(next_player_position->y).at(next_player_position->x)->isWall()){
        return;
    } else{
        //delete reaction on player
        map.at(player_position.y).at(player_position.x)->removePlayer();

        //set new position
        player_position.x = next_player_position->x;
        player_position.y = next_player_position->y;

        //set reaction on player
        map.at(player_position.y).at(player_position.x)->setPlayer();

        //clear memory
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
        case Stay:
            break;
    }
    Position* next_player_position = new Position();
    next_player_position->x = player_position.x + dx;
    next_player_position->y = player_position.y + dy;
    return next_player_position;
};

Map::~Map(){
    for (auto row: this->map){
        for (auto cell: row){
            delete cell;
        }
    }
};
