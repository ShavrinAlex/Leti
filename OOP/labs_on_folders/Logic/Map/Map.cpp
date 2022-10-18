#include "Map.hpp"
#define WIDTH 5
#define HEIGHT 5
#define START_POSITION_X 0
#define START_POSITION_Y 0
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
            if (this->player->pos->x == x && this->player->pos->y == y){
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
    //create player
    this->player = new PlayerElem;
    this->player->entity = nullptr;
    Position* pos = new Position;
    pos->x = START_POSITION_X;
    pos->y = START_POSITION_Y;
    this->player->pos = pos;

    createMap();
};
Map::Map(int width, int height){
    this->width = width;
    this->height = height;

    //create player
    this->player = new PlayerElem;
    this->player->entity = nullptr;
    Position* pos = new Position;
    pos->x = START_POSITION_X;
    pos->y = START_POSITION_Y;
    this->player->pos = pos;

    createMap();
};

//set player
void Map::setPlayer(Player* player){
    this->player->entity = player;
};

//coping
Map::Map(const Map& obj){
    //std::cout<<"map "<<this<<" constr copy\n";
    this->player->pos->x = obj.player->pos->x;
    this->player->pos->y = obj.player->pos->y;
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
        this->player->pos->x = obj.player->pos->x;
        this->player->pos->y = obj.player->pos->y;
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
    std::swap(this->player->pos->x, obj.player->pos->x);
    std::swap(this->player->pos->y, obj.player->pos->y);
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
        std::swap(this->player->pos->x, obj.player->pos->x);
        std::swap(this->player->pos->y, obj.player->pos->y);
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

//set controllers
void Map::setControllers(EntityController* player_controller, EntityController* enemies_controller){
    this->player_controller = player_controller;
    this->enemies_controller = enemies_controller;
};

//add enemy
void Map::addEnemy(Entity* enemy, Position* pos){
    //create enemy struct
    EntityElem* en = new EntityElem;
    en->entity = enemy;
    en->pos = pos;

    //add enemy
    this->enemies.emplace_back(*en);
};

//remove enemy
void Map::removeEnemy(Entity* enemy){
    //search enemy
    for (int i = 0; i < this->enemies.size(); i++){
        if (this->enemies.at(i).entity == enemy){
            delete this->enemies.at(i).entity;
            delete this->enemies.at(i).pos;
            auto iter = this->enemies.begin();
            this->enemies.erase(iter + i);
        }
    }
};

//get enemies
Enemies Map::getEnemies(){
    return this->enemies;
};

//get cell
Cell* Map::getCell(int pos_x, int pos_y){
    return this->map.at(pos_y).at(pos_x);
};

//check enemy on cell
bool Map::isHereEnemy(Position* pos){
    //check absence enemies
    if (this->enemies.size() == 0){
        return false;
    }

    //check position all enemies
    for (int i = 0; i < this->enemies.size(); i++){
        if (this->enemies.at(i).pos->x == pos->x && this->enemies.at(i).pos->y == pos->y){
            return true;
        }
    }
    return false;
};

//calculate next entity position
Position* Map::calculateNextEntityPosition(Entity* entity){
    //calculate increments
    int dx = 0;
    int dy = 0;
    switch (entity->getDirection()){
        case Right:
            dx = entity->getSpeed();
            break;
        case Left:
            dx = -entity->getSpeed();
            break;
        case Up:
            dy = -entity->getSpeed();
            break;
        case Down:
            dy = entity->getSpeed();
            break;
    }
    Position* next_position = new Position();

    //calculate next position
    if (entity == this->player->entity){
        next_position->x = this->player->pos->x + dx;
        next_position->y = this->player->pos->y + dy;
    } else{
        //search entity
        for (int i = 0; i < this->enemies.size(); i++){
            if (this->enemies.at(i).entity == entity){
                next_position->x = this->enemies.at(i).pos->x + dx;
                next_position->y = this->enemies.at(i).pos->y + dy;
            }
        }
    }
    //convert damage position
    this->convertEntityPosition(next_position);
    return next_position;
};

//convert entity position
void Map::convertEntityPosition(Position* position){
    if (position->x >= this->width){
        position->x -= this->width;        
    }
    if (position->x < 0){
        position->x += this->width;        
    }
    if (position->y >= this->height){
        position->y -= this->height;        
    }
    if (position->y < 0){
        position->y += this->height;        
    }
};

//move entity
void Map::moveEntity(Entity* entity){
    //calculate next entity position
    Position* next_position = this->calculateNextEntityPosition(entity);
    
    //check cell on wall and on enemy
    if (map.at(next_position->y).at(next_position->x)->isWall() || this->isHereEnemy(next_position) || (this->player->pos->x == next_position->x && this->player->pos->y == next_position->y)){
        return;
    }

    //move entity on new position
    if (entity == this->player->entity){
        //delete reaction on player
        map.at(this->player->pos->y).at(this->player->pos->x)->removePlayer();

        //set new position
        this->player->pos->x = next_position->x;
        this->player->pos->y = next_position->y;

        //set reaction on player
        map.at(this->player->pos->y).at(this->player->pos->x)->setPlayer();
    } else{
        //search entity
        for (int i = 0; i < this->enemies.size(); i++){
            if (this->enemies.at(i).entity == entity){
                this->enemies.at(i).pos->x = next_position->x;
                this->enemies.at(i).pos->y = next_position->y;
            }
        }
    }
    //clear memory
    delete next_position;
};

//make damage
void Map::makeDamage(Entity* entity){
    //calculate position to damage
    Position* damage_position = this->calculateNextEntityPosition(entity);

    //check entity agressor
    if (entity == this->player->entity){
        //check entity on damage position
        if (this->isHereEnemy(damage_position)){
            for (int i = 0; i < this->enemies.size(); i++){
                if (this->enemies.at(i).pos->x == damage_position->x && this->enemies.at(i).pos->y == damage_position->y){
                    this->enemies_controller->takeDamage(entity->getDamage(), this->enemies.at(i).entity);
                }
            }
        }     
    } else{
        //check player on danmage position
        if (this->player->pos->x == damage_position->x && this->player->pos->y == damage_position->y){
            this->player_controller->takeDamage(entity->getDamage(), this->player->entity);
        }
    }

    //clear memory
    delete damage_position;
};

//get player position
Position* Map::getPlayerPosition(){
    return this->player->pos;
};

//get enemy position
Position* Map::getEnemyPosition(Entity* entity){
    Position* pos = nullptr;
    for (int i = 0; i < this->enemies.size(); i++){
        if (this->enemies.at(i).entity == entity){
            pos = this->enemies.at(i).pos;
        }
    }
    return pos;   
};

Map::~Map(){
    for (auto row: this->map){
        for (auto cell: row){
            delete cell;
        }
    }
};
