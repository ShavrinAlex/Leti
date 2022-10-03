#pragma once
#include <SFML/Graphics.hpp>
#include "../Headlines/CellView.hpp"
#include "../Headlines/MapView.hpp"
#include "../Headlines/EntityView.hpp"
#include "../Headlines/PlayerView.hpp"
#include <string>
#define WINDOW_NAME "My game"

class GraphicArts{
    private:
        int width;
        int height;
        std::string window_name;
        sf::RenderWindow window;
    public:
        //initialization
        GraphicArts(int width, int height, std::string window_name = WINDOW_NAME);
        
        //check is open window
        bool isOpen();

        //close window
        void closeWindow();

        //poll event
        void pollEvent();

        //draw entity
        void drawEntity(EntityView& entity_view);

        //draw player
        void drawPlayer(PlayerView& player_view);

        //draw map
        void drawMap(MapView& map_view);

        //window clear
        void clear();

        //window display
        void display();
};
