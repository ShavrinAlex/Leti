#include "GraphicArts.hpp"
#define CELL_SIDE 98

//initialization
GraphicArts::GraphicArts(int width, int height, std::string window_name){
    //size in pixels
    this->width = width * CELL_SIDE;
    this->height = height * CELL_SIDE;

    //set name window
    this->window_name = window_name;

    //create window
    this->window.create(sf::VideoMode(this->width , this->height), this->window_name);
    this->window.setFramerateLimit(60);
};

//check is open window
bool GraphicArts::isOpen(){
    return this->window.isOpen();
};

//close window
void GraphicArts::closeWindow(){
    this->window.close();
};

//poll event
void GraphicArts::pollEvent(){
    sf::Event event;
    while (this->window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            this->window.close();
        }
    }
};

//draw player
void GraphicArts::drawPlayer(PlayerView& player_view){
    //draw entity
    this->drawEntity(player_view);

    //draw ammunition scale
    this->window.draw(*player_view.getAmmunitionScaleStroke());
    this->window.draw(*player_view.getAmmunitionScale());
};

//draw entity
void GraphicArts::drawEntity(EntityView& entity_view){
    //draw sprite
    this->window.draw(*entity_view.getSprite());

    //draw health scale
    this->window.draw(*entity_view.getHealthScaleStroke());
    this->window.draw(*entity_view.getHealthScale());
};

//draw map
void GraphicArts::drawMap(MapView& map_view){
    for (int y = 0; y < this->height/CELL_SIDE; y++){
        for (int x = 0; x < this->width/CELL_SIDE; x++){
            //get cell
            CellView* cell_view = map_view.getCellView(x, y);
            //get cell draw object
            sf::RectangleShape* cell = cell_view->getDrawObject();
            //draw
            this->window.draw(*cell);
        }
    }
};

//window clear
void GraphicArts::clear(){
    this->window.clear();
};

//window display
void GraphicArts::display(){
    this->window.display();
};
