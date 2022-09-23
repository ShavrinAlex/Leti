#include "Game.hpp"
#include "Player.hpp"
#include "CommandReader.hpp"
#define START_POSITION {0, 0}
#define PLAYER_W 98
#define PLAYER_H 98

//initialization
Game::Game(RenderWindow& window, int map_width, int map_height){
    this->window = window;    
    this->map_width = map_width;
    this->map_height = map_height;
};

//game
int Game::game_executor(){
    //create map
    Map map = Map(map_width, map_height);
    MapView map_view = MapView(map);

    //create player
    Player player = Player();
    EntityView player_view = EntityView(player, PLAYER_W, PLAYER_H, "hero1");

    //create command reader
    CommandReader com_reader = CommandReader();

    //set player on map
    map.setPlayerPosition((Position)START_POSITION);

    return 0;
};
