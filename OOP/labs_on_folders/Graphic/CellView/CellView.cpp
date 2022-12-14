#include "CellView.hpp"

//initialization
CellView::CellView(Cell* cell, int x, int y, int side){
    //logic cell
    this->cell = cell;
    this->cell->addObserver(this);

    //event view
    updateEventView();

    //cell side
    this->side = side;

    //coordinates in pixels
    this->position.x = x * side;
    this->position.y = y * side;

    //draw object
    this->cell_view = new sf::RectangleShape(sf::Vector2f(side, side));
    this->cell_view->setOutlineThickness(-1);
    this->cell_view->setPosition(this->position.x, this->position.y);
    updateColor();
};

//change color
void CellView::updateColor(){
    if (this->cell->isWall()){
        this->cell_view->setFillColor(sf::Color(65, 105, 225));
        this->cell_view->setOutlineColor(sf::Color(0, 0, 139));
    } else{
        this->cell_view->setFillColor(sf::Color(255, 255, 0));
        this->cell_view->setOutlineColor(sf::Color(255, 140, 0));
    }
    if (this->cell->isHerePlayer()){
        this->cell_view->setFillColor(sf::Color(173, 255, 47));
    }
};

//update event view
void CellView::updateEventView(){
    if (this->cell->getEvent() == nullptr){
        this->removeEventView();
    }
};

//get draw obgect
sf::RectangleShape* CellView::getDrawObject(){
    return this->cell_view;
};

//set and remove event view
void CellView::setEventView(EventView* ev){
    this->event_view = ev;
};
void CellView::removeEventView(){
    this->event_view = nullptr;
};

//get event view
EventView* CellView::getEventView(){
    return this->event_view;
};

//update all
void CellView::update(){
    updateColor();
    updateEventView();
}

//destruction
CellView::~CellView(){
    this->cell = nullptr;
    this->removeEventView();
    delete this->cell_view;
};
