#include "../Headlines/Controller.hpp"

//initialization
Controller::Controller(Player* player, Map* map, PlayerView* player_view, CommandReader* com_reader){
    this->player = player;
    this->map = map;
    this->player_view = player_view;
    this->com_reader = com_reader;
};

//send
void Controller::send(std::string message, GameElement* element){
    this->time = this->clock.getElapsedTime().asMicroseconds();
    this->clock.restart();
    this->time = time/800;
    this->timer += time;
    //std::cout<<"time = "<<time<<'\n';
    //std::cout<<"timer = "<<timer<<'\n';
    if (element == this->com_reader){
        if (this->timer >= 350){
            if (message == "move player right"){
                movePlayer(Right);
            }
            if (message == "move player left"){
                movePlayer(Left);
            }
            if (message == "move player up"){
                movePlayer(Up);
            }
            if (message == "move player down"){
                movePlayer(Down);
            }
        }
    }
};

//move player
void Controller::movePlayer(Direction dir){
    this->player->setDirection(dir);
    this->map->setPlayerPosition(map->calculateNextPlayerPosition(player->getSpeed(), dir));
    this->player_view->setPosition(map->getPlayerPosition());
    this->timer = 0;
};
