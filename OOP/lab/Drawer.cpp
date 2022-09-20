#include "Drawer.h"
#include <iostream>

//set controller
void Drawer::setController(Controller *controller){
    this->controller = controller;
};

//draw map
void Drawer::drawMap(sf::RenderWindow *window){
    for (int y = 0; y < controller->getMapHeight(); y++){
        for (int x = 0; x < controller->getMapWidth(); x++){
            //get cell
            sf::RectangleShape* cell = controller->getCellDrawObject(x, y);
            //set rectangle shape position
            cell->setPosition(x * controller->getCellSide(x, y), y * controller->getCellSide(x, y));
            //std::cout<<"x = "<<x * controller->getCellSide(x, y)<<" y = "<<y * controller->getCellSide(x, y)<<'\n';
            //draw cell rect
            window->draw(*cell);
        }
    }
};

//draw player
void Drawer::drawPlayer(sf::RenderWindow *window){
    //get sprite
    sf::Sprite* player_sprite = controller->getPlayerDrawObject();
    
    //set sprite position
    player_sprite->setPosition(controller->getPlayerPosition().x * controller->getPlayerWidth(), controller->getPlayerPosition().y * controller->getPlayerWidth());

    //draw sprite
    window->draw(*player_sprite);
};
