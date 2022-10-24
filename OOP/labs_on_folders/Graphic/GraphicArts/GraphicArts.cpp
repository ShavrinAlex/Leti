#include "GraphicArts.hpp"
#define CELL_SIDE 98
#define START_WINDOW_HEIGHT 5*CELL_SIDE
#define START_WINDOW_WIDTH 5*CELL_SIDE

//initialization
GraphicArts::GraphicArts():GraphicArts(START_WINDOW_WIDTH, START_WINDOW_HEIGHT){};
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
    this->window.draw(*player_view.getEnergyScale());
    this->window.draw(*player_view.getEnergyScaleStroke());

    //draw armor scale
    this->window.draw(*player_view.getArmorScale());
    this->window.draw(*player_view.getArmorScaleStroke());
};

//draw entity
void GraphicArts::drawEntity(EntityView& entity_view){
    //draw sprite
    this->window.draw(*entity_view.getSprite());

    //draw health scale
    this->window.draw(*entity_view.getHealthScale());
    this->window.draw(*entity_view.getHealthScaleStroke());
};

//draw map
void GraphicArts::drawMap(MapView& map_view){
    //draw map
    for (int y = 0; y < this->height/CELL_SIDE; y++){
        for (int x = 0; x < this->width/CELL_SIDE; x++){
            //get cell view
            CellView* cell_view = map_view.getCellView(x, y);
            //get cell draw object
            sf::RectangleShape* cell = cell_view->getDrawObject();
            //draw cell view
            this->window.draw(*cell);

            //get event view
            EventView* event_view = cell_view->getEventView();
            if (event_view){
                //get event draw object
                sf::Sprite* event = event_view->getSprite();
                //draw event view
                this->window.draw(*event);
            }
        }
    }

    //draw enemies
    for(size_t i = 0; i < map_view.getEnemiesView().size(); i++){
        this->drawEntity(*(map_view.getEnemiesView()).at(i));
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
