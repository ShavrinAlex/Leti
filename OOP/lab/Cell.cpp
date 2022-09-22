#include "Cell.h"
#include <iostream>

//initialization
Cell::Cell(float side, bool is_busy, bool hero_is_here){
    this->side = side;
    this->color = sf::Color::Yellow;
    this->is_busy = is_busy;
    this->hero_is_here = hero_is_here;
    cell = create_cell();
};

//create cell
sf::RectangleShape* Cell::create_cell(){
    sf::RectangleShape *cell = new sf::RectangleShape(sf::Vector2f(side, side));
    cell->setPosition(sf::Vector2f(100.f, 100.f));
    cell->setFillColor(color);
    cell->setOutlineThickness(-1);
    cell->setOutlineColor(sf::Color::Red);
    
    return cell;
};

//get cell obj for draw
sf::RectangleShape* Cell::getDrawObject(){
    return cell;
};

//get side
float Cell::getSide(){
    return side;
};

//check is bussy cell
bool Cell::is_busy_cell(){
    return is_busy;
};

//set hero
void Cell::setHero(bool is_here){
    //std::cout<<"is_here\n";
    this->hero_is_here = is_here;
};

//reaction on hero
void Cell::reaction_on_hero(){
    if (hero_is_here){
        cell->setFillColor(sf::Color::Green);
    } else{
        cell->setFillColor(sf::Color::Yellow);
    }
    
};

/*
//draw cell
void Cell::draw(sf::RenderWindow *window){
    window->draw(*cell);
};
*/


//update
void Cell::update(){
    reaction_on_hero();
    if (is_busy){
        cell->setFillColor(sf::Color::Blue);
    }
};

/*
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
*/

//position x and y
/*
float Cell::get_position_x(){
    return pos_x;
};
float Cell::get_position_y(){
    return pos_y;
};

void Cell::set_position_x(float pos_x){
    this->pos_x = pos_x;
};
void Cell::set_position_y(float pos_y){
    this->pos_y = pos_y;
};
*/