#include "Cell.h"
#include <iostream>

//initialization
Cell::Cell(int num_x, int num_y, float side, bool is_bussy){
    this->pos_x = float(num_x * side);
    this->pos_y = float(num_y * side);
    this->side = side;
    this->color = sf::Color::Yellow;
    this->is_bussy = is_bussy;
    cell = create_cell();
};

//create cell
sf::RectangleShape* Cell::create_cell(){
    sf::RectangleShape *cell = new sf::RectangleShape(sf::Vector2f(side, side));
    cell->setPosition(pos_x, pos_y);
    cell->setFillColor(color);
    cell->setOutlineThickness(-1);
    cell->setOutlineColor(sf::Color::Red);
    return cell;
};

//draw cell
void Cell::draw(sf::RenderWindow *window){
    window->draw(*cell);
};

//position x and y
/*
float Cell::get_position_x(){
    return pos_x;
};
float Cell::get_position_y(){
    return pos_y;
};
*/
void Cell::set_position_x(float pos_x){
    this->pos_x = pos_x;
};
void Cell::set_position_y(float pos_y){
    this->pos_y = pos_y;
};

//side
float Cell::get_side(){
    return side;
};
/*
//check hero is here
bool hero_is_here(Player *hero){
    float x = hero->get_position_x();
    float y = hero->get_position_y();

    if ((x >= pos_x) && (x <= pos_x + side) && (y >= pos_y) && (y <= pos_y + side)){
        return true;
    } else{
        return false;
    }
};

//check is bussy cell
bool Cell::is_bussy_cell(){
    return is_bussy;
};

//reaction on hero
void Cell::reaction_on_hero(Player *hero){
    if (hero_is_here(hero)){
        cell.setFillColor(sf::Color::Green);
    }
};
*/