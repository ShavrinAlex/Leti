#include "CellView.hpp"

//initialization
CellView::CellView(Cell* cell, int x, int y, int side){
    this->cell = cell;
    this->side = side;

    //coordinates in pixels
    this->x = x * side;
    this->y = y * side;

    //draw object
    cell_view = new sf::RectangleShape(sf::Vector2f(side, side));
    cell_view->setOutlineThickness(-1);
    if (cell->isWall()){
        cell_view->setOutlineColor(sf::Color(0, 0, 139));
    } else{
        cell_view->setOutlineColor(sf::Color(255, 140, 0));
    }
    cell_view->setPosition(this->x, this->y);
    updateColor();
};

//change color
void CellView::updateColor(){
    if (cell->isWall()){
        cell_view->setFillColor(sf::Color(65, 105, 225));
    } else{
        cell_view->setFillColor(sf::Color(255, 255, 0));
    }
    if (cell->isHerePlayer()){
        cell_view->setFillColor(sf::Color(173, 255, 47));
    }
};

//get draw obgect
sf::RectangleShape* CellView::getDrawObject(){
    updateColor();
    return cell_view;
};
