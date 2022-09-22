#include "CellView.h"

//initialization
CellView::CellView(Cell& cell, int x, int y, int side = SIDE){
    this->cell = cell;
    this->side = side;

    //coordinates in pixels
    this->x = x * side;
    this->y = y * side;

    //draw object
    cell_view = new sf::RectangleShape(sf::Vector2f(side, side));
    cell_view->setOutlineThickness(-1);
    cell_view->setOutlineColor(sf::Color::Red);
    cell_view->setPosition(this->x, this->y);
    updateColor();
};

//change color
void CellView::updateColor(){
    if (cell.isWall()){
        cell_view->setFillColor(sf::Color::Blue);
    } else{
        cell_view->setFillColor(sf::Color::Yellow);
    }
    if (cell.isHerePlayer()){
        cell_view->setFillColor(sf::Color::Green);
    }
};

//get draw obgect
sf::RectangleShape* CellView::getDrawObject(){
    updateColor();
    return cell_view;
};
