#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Player.h"
#include "Map.h"
#include "Drawer.h"
#include <iostream>
#define CELL_SIZE 98

//initialization
Controller::Controller(Player* player, Map* map, Drawer* drawer){
    this->player = player;
    this->map = map;
    this->drawer = drawer;
};

//calculate next player position
void Controller::calculateNextPlayerPosition(){
    switch (player->getDirection()){
        case 1:
            player->setDeltaX(player->getSpeed());
            player->setDeltaY(0);
            break;
        case 2:
            player->setDeltaX(-player->getSpeed());
            player->setDeltaY(0);
            break;
        case 3:
            player->setDeltaX(0);
            player->setDeltaY(-player->getSpeed());
            break;
        case 4:
            player->setDeltaX(0);
            player->setDeltaY(player->getSpeed());
            break;
    }
    next_player_position.x = map->getPlayerPosition().x + player->getDeltaX();
    next_player_position.y = map->getPlayerPosition().y + player->getDeltaY();
};

//move player
void Controller::movePlayer(int key){
    //get new position
    
    player->setSpeed(1); //cell_size
    player->setDirection(key);
    calculateNextPlayerPosition();
    player->setSpeed(0);
    //std::cout<<"controller move\n";
    //std::cout<<"x = "<<next_player_position.x<<" y = "<<next_player_position.y<<'\n';
    //set new position if it can
    map->movePlayer(next_player_position);
    
    map->update();
};

int Controller::getMapHeight(){
    return map->getHeight();
};
int Controller::getMapWidth(){
    return map->getWidth();
};

Position Controller::getPlayerPosition(){
    return map->getPlayerPosition();
};

int Controller::getCellSide(int pos_x, int pos_y){
    return map->getCell(pos_x, pos_y)->getSide();
};

sf::RectangleShape* Controller::getCellDrawObject(int pos_x, int pos_y){
    return map->getCell(pos_x, pos_y)->getDrawObject();
};

sf::Sprite* Controller::getPlayerDrawObject(){
    return player->getDrawObject();
};

int Controller::getPlayerWidth(){
    return player->getWidth();
};
int Controller::getPlayerHeight(){
    return player->getHeight();
};
