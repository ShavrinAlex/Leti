#pragma once
#include "Position.h"
class Player;
class Map;
class Drawer;

class Controller{
    private:
        Player* player;
        Map* map;
        Drawer* drawer;
        Position next_player_position;
        void calculateNextPlayerPosition();
    public:
        Controller(Player* player, Map* map, Drawer* drawer);
        void movePlayer(int key);
        int getMapHeight();
        int getMapWidth();
        Position getPlayerPosition();
        int getCellSide(int pos_x, int pos_y);
        sf::RectangleShape* getCellDrawObject(int pos_x, int pos_y);
        sf::Sprite* getPlayerDrawObject();
        int getPlayerWidth();
        int getPlayerHeight();
};
