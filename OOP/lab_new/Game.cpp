#include "Game.hpp"
#include "Player.hpp"
#include "CommandReader.hpp"
#include "Enumerations.hpp"
#define PLAYER_W 98
#define PLAYER_H 98
#define START_POSITION {1, 1}
#include <iostream>

//initialization
Game::Game(int map_width, int map_height){
    this->map_width = map_width;
    this->map_height = map_height;
    this->graphic_arts = new GraphicArts(this->map_width, this->map_height);
};

//game
int Game::game_executor(){
    //create map
    Map map = Map(map_width, map_height);
    MapView map_view = MapView(&map);

    //create player
    Player player = Player();
    EntityView player_view = EntityView(&player, PLAYER_W, PLAYER_H, "hero1.png");

    //create command reader
    CommandReader com_reader = CommandReader();

    //set player on map

    //map.setPlayerPosition();

    //main loop
    float timer = 0;
    sf::Clock clock;
    //std::cout<<player.getSpeed()<<'\n';
    player.setSpeed(1);
    while (graphic_arts->isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        timer += time;

        graphic_arts->pollEvent();

        Direction key = com_reader.getPressedKey();
        
        if (timer > 350){
            switch (key){
                case Right:
                    player.setDirection(Right);
                    map.setPlayerPosition(map.calculateNextPlayerPosition(player.getSpeed(), Right));
                    player_view.setPosition(map.getPlayerPosition());
                    timer = 0;
                    break;
                case Left:
                    player.setDirection(Left);
                    map.setPlayerPosition(map.calculateNextPlayerPosition(player.getSpeed(), Left));
                    player_view.setPosition(map.getPlayerPosition());
                    timer = 0;
                    break;
                case Up:
                    player.setDirection(Up);
                    map.setPlayerPosition(map.calculateNextPlayerPosition(player.getSpeed(), Up));
                    player_view.setPosition(map.getPlayerPosition());
                    timer = 0;
                    break;
                case Down:
                    player.setDirection(Down);
                    map.setPlayerPosition(map.calculateNextPlayerPosition(player.getSpeed(), Down));
                    player_view.setPosition(map.getPlayerPosition());
                    timer = 0;
                    break;
                default:
                    break;
            }
        }
        //std::cout<<player.getDirection()<<"\n";
        graphic_arts->clear();
        graphic_arts->drawMap(map_view);
        graphic_arts->drawEntity(player_view);
        graphic_arts->display();
    }

    return 0;
};
