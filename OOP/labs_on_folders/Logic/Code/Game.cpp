#include "../Headlines/Game.hpp"
#include "../Headlines/Player.hpp"
#include "../../Graphic/Headlines/PlayerView.hpp"
#include "../Headlines/CommandReader.hpp"
#include "../Headlines/Enumerations.hpp"
#include "../Headlines/StartDialog.hpp"
#include "../Headlines/Controller.hpp"
#define PLAYER_W 98
#define PLAYER_H 98
#define START_POSITION {1, 1}
#define PLAYER_IMAGE "../../Images/Entities/hero1.png"
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
    PlayerView player_view = PlayerView(&player, PLAYER_W, PLAYER_H, map.getPlayerPosition(),PLAYER_IMAGE);

    //create command reader
    CommandReader com_reader = CommandReader();

    //create controller(mediator)
    Controller contrtoller = Controller(&player, &map, &player_view, &com_reader);
    
    player.setMediator(&contrtoller);
    map.setMediator(&contrtoller);
    player_view.setMediator(&contrtoller);
    com_reader.setMediator(&contrtoller);

    //main loop
    while (graphic_arts->isOpen()){
        //check close window
        graphic_arts->pollEvent();

        //actions
        com_reader.getPressedKey();
    
        //draw all
        this->graphic_arts->clear();
        this->graphic_arts->drawMap(map_view);
        this->graphic_arts->drawPlayer(player_view);
        this->graphic_arts->display();
        
    }
    return 0;
};

//destruction
Game::~Game(){
    delete graphic_arts;
};
