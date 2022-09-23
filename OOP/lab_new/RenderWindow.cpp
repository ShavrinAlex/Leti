#include "RenderWindow.hpp"
#define CELL_SIDE 98

//initialization
RenderWindow::RenderWindow(int width, int height, std::string window_name = WINDOW_NAME){
    //coardinates in pixels
    this->width = width * CELL_SIDE;
    this->height = height * CELL_SIDE;

    this->window_name = window_name;

    window = new sf::RenderWindow(sf::VideoMode(this->height , this->width), window_name);
    window->setFramerateLimit(60);
};

//draw entity
void RenderWindow::drawEntity(EntityView& entity){
    //draw sprite
    window->draw(*entity.getDrawObject());
};

//draw map
void RenderWindow::drawMap(MapView& map_view){
    for (int y = 0; y < height/CELL_SIDE; y++){
        for (int x = 0; x < width/CELL_SIDE; x++){
            //get cell
            CellView* cell_view = map_view.getCellView(x, y);
            //get cell draw object
            sf::RectangleShape* cell = cell_view->getDrawObject();
            //draw
            window->draw(*cell);
        }
    }
};
