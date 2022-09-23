#include <SFML/Graphics.hpp>
#include "CellView.hpp"
#include "MapView.hpp"
#include "EntityView.hpp"
#include <string>
#define WINDOW_NAME "My Game"

class RenderWindow{
    private:
        int width;
        int height;
        std::string window_name;
        sf::RenderWindow* window;
    public:
        //initialization
        RenderWindow(int width, int height, std::string window_name = WINDOW_NAME);

        //draw entity
        void drawEntity(EntityView& entity);

        //draw map
        void drawMap(MapView& map_view);
};
