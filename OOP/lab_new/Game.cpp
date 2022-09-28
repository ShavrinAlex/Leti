#include "Game.hpp"
#include "Player.hpp"
#include "CommandReader.hpp"
#include "Enumerations.hpp"
#include "StartDialog.hpp"
#define PLAYER_W 98
#define PLAYER_H 98
#define START_POSITION {1, 1}
#define PLAYER_IMAGE "hero1.png"
#include <iostream>

//initialization
Game::Game(){
    StartDialog start_dialog = StartDialog();
    this->map_width = start_dialog.getWidth();
    this->map_height = start_dialog.getHeight();
    this->graphic_arts = new GraphicArts(this->map_width, this->map_height);
};

//game start
int Game::startGame(){
    /*
    Cell cell1 = Cell(true, true);
    Cell cell2 = std::move(cell1);

    Cell cell3(false, true);
    Cell cell4(cell3);
    cell3 = cell4;
    cell4 = std::move(cell3);

    Map map1 = Map();
    Map map2 = std::move(map2);

    Map map3 = Map();
    Map map4 = map3;
    map3 = map4;
    map4 = std::move(map3);
    */
    //create map
    Map map = Map(this->map_width, this->map_height);
    MapView map_view = MapView(&map);

    //create player
    Player player = Player();
    player.setSpeed(1);
    EntityView player_view = EntityView(&player, PLAYER_W, PLAYER_H, PLAYER_IMAGE);

    //create command reader
    CommandReader com_reader = CommandReader();
    //main loop
    float timer = 0;
    sf::Clock clock;
    while (graphic_arts->isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        timer += time;

        //check close window
        graphic_arts->pollEvent();

        //get pressed key
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

        //draw all
        this->graphic_arts->clear();
        this->graphic_arts->drawMap(map_view);
        this->graphic_arts->drawEntity(player_view);
        this->graphic_arts->display();
    }
    return 0;
};

//destruction
Game::~Game(){
    delete graphic_arts;
};
