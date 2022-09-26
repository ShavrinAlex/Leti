#include "GraphicArts.hpp"
#define CELL_SIDE 98

//initialization
GraphicArts::GraphicArts(int width, int height, std::string window_name){
    //size in pixels
    this->width = width * CELL_SIDE;
    this->height = height * CELL_SIDE;

    this->window_name = window_name;

    this->window.create(sf::VideoMode(this->height , this->width), this->window_name);
    this->window.setFramerateLimit(60);
};

//check is open window
bool GraphicArts::isOpen(){
    return window.isOpen();
};

//close window
void GraphicArts::closeWindow(){
    window.close();
};

//poll event
void GraphicArts::pollEvent(){
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
    }
};

//draw entity
void GraphicArts::drawEntity(EntityView& entity_view){
    //draw sprite
    window.draw(*entity_view.getDrawObject());
};

//draw map
void GraphicArts::drawMap(MapView& map_view){
    for (int y = 0; y < height/CELL_SIDE; y++){
        for (int x = 0; x < width/CELL_SIDE; x++){
            //get cell
            CellView* cell_view = map_view.getCellView(x, y);
            //get cell draw object
            sf::RectangleShape* cell = cell_view->getDrawObject();
            //draw
            window.draw(*cell);
        }
    }
};

//window clear
void GraphicArts::clear(){
    window.clear();
};

//window display
void GraphicArts::display(){
    window.display();
};
