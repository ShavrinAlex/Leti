#include "../Headlines/Controller.hpp"

//initialization
Controller::Controller(Player* player, Map* map, PlayerView* player_view, CommandReader* com_reader){
    this->player = player;
    this->map = map;
    this->player_view = player_view;
    this->com_reader = com_reader;
    this->time = clock();
};

//send
void Controller::send(std::string message, GameElement* element){
    this->timer = (clock() - this->time)/CLOCKS_PER_SEC;
    //std::cout<<timer<<'\n';
    if (element == this->com_reader){
        if (this->timer >= 0.09){
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
    this->time = clock();
};
