#pragma once
#include "Position.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "Drawer.h"
#include "CommandReader.h"

class MainLoop{
    private:
        int map_height;
        int map_width;
        Position player_position;
    public:
        //player
        void setPlayerPosition(Position pp);

        //map
        void setMapSize(int h, int w);

        //executor main loop
        int executor(sf::RenderWindow * window);
};
