#include "Cell.h"
#include <iostream>

//initialization
Cell::Cell(int num_x, int num_y, float side, bool is_busy){
    this->pos_x = float(num_x * side);
    this->pos_y = float(num_y * side);
    this->side = side;
    this->color = sf::Color::Yellow;
    this->is_busy = is_busy;
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

//check hero is here
bool Cell::hero_is_here(Player *hero){
    float hero_x = hero->get_position_x() + hero->get_width()/2;
    float hero_y = hero->get_position_y() + hero->get_height()/1.2;

    if ((hero_x >= pos_x) && (hero_x <= pos_x + side) && (hero_y >= pos_y) && (hero_y <= pos_y + side)){
        return true;
    } else{
        return false;
    }
};

//check is bussy cell
bool Cell::is_busy_cell(){
    return is_busy;
};

//reaction on hero
void Cell::reaction_on_hero(){
    cell->setFillColor(sf::Color::Green);
};

//update
void Cell::update(Player *hero){
    if (hero_is_here(hero)){
        reaction_on_hero();
    } else{
        cell->setFillColor(sf::Color::Yellow);
    }
};
