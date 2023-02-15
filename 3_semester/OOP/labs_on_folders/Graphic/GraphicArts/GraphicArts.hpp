#pragma once
#include <SFML/Graphics.hpp>
#include "../CellView/CellView.hpp"
#include "../MapView/MapView.hpp"
#include "../EntitiesView/EntityView/EntityView.hpp"
#include "../EntitiesView/PlayerView/PlayerView.hpp"
#include <string>
#include <memory>
#define WINDOW_NAME "My game"

class GraphicArts{
    private:
        int width;
        int height;
        std::string window_name;
        sf::RenderWindow window;

        //draw entity
        void drawEntity(EntityView& entity_view);

        //draw player
        void drawPlayer(PlayerView& player_view);
    public:
        //initialization
        GraphicArts();
        GraphicArts(int width, int height, std::string window_name = WINDOW_NAME);
        
        //check is open window
        bool isOpen();

        //close window
        void closeWindow();

        //poll event
        std::shared_ptr<sf::Event> pollEvent();

        //draw map
        void drawMap(MapView& map_view);

        //window clear
        void clear();

        //window display
        void display();
};
