#include "../Headlines/Game.hpp"
#include "../Headlines/Player.hpp"
#include "../../Graphic/Headlines/PlayerView.hpp"
#include "../Headlines/CommandReader.hpp"
#include "../Headlines/Enumerations.hpp"
#include "../Headlines/StartDialog.hpp"
#include "../Headlines/Controller.hpp"
#include "../Headlines/FactoryEventOnPlayer.hpp"
#include "../Headlines/FactoryEventOnMap.hpp"
#include "../Headlines/FactoryEventOnGame.hpp"
#include "../Headlines/EventGenerator.hpp"
#define PLAYER_W 98
#define PLAYER_H 98
#define START_POSITION {1, 1}
#define PLAYER_IMAGE "./Graphic/Images/Entities/hero1.png"

//initialization
Game::Game(){
    StartDialog start_dialog = StartDialog();
    this->map_width = start_dialog.getWidth();
    this->map_height = start_dialog.getHeight();
    this->graphic_arts = new GraphicArts(this->map_width, this->map_height);
    this->game_status = CONTINUES;
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
    PlayerView player_view = PlayerView(&player, PLAYER_W, PLAYER_H, map.getPlayerPosition(), PLAYER_IMAGE);

    //create command reader
    CommandReader com_reader = CommandReader();

    //create controller(mediator)
    Controller contrtoller = Controller(&player, &map, &player_view, &com_reader);
    
    //set mediator
    player.setMediator(&contrtoller);
    map.setMediator(&contrtoller);
    player_view.setMediator(&contrtoller);
    com_reader.setMediator(&contrtoller);
    
    //create event generator
    EventGenerator event_generator = EventGenerator(&map, &map_view);

    //create event fabrics
    FactoryEventOnPlayer factory_event_on_player = FactoryEventOnPlayer(&player);
    FactoryEventOnGame factory_event_on_game = FactoryEventOnGame(this);
    FactoryEventOnMap factory_event_on_map = FactoryEventOnMap(&map, &factory_event_on_game, &event_generator);

    event_generator.generateHealthEvent(&factory_event_on_player);
    event_generator.generateArmorEvent(&factory_event_on_player);
    event_generator.generateEnergyEvent(&factory_event_on_player);
    event_generator.generateSetWallEvent(&factory_event_on_map);
    event_generator.generateSetWinGameEvent(&factory_event_on_map);
    event_generator.generateEndGameEvent(&factory_event_on_game);
    event_generator.generateEndGameEvent(&factory_event_on_game);
    event_generator.generateEndGameEvent(&factory_event_on_game);

    //main loop
    while (graphic_arts->isOpen()){
        //check close window
        this->graphic_arts->pollEvent();
        
        //actions
        com_reader.getPressedKey();
    
        //draw all
        this->graphic_arts->clear();
        this->graphic_arts->drawMap(map_view);
        this->graphic_arts->drawPlayer(player_view);
        this->graphic_arts->display();

        //check end game
        this->checkEndGame(&player);
    }
    return 0;
};

//set game status
void Game::setGameStatus(GameStatus game_status){
    this->game_status = game_status;
};

//check end game
void Game::checkEndGame(Player* player){
    if (this->game_status == WIN || this->game_status == LOOSE){
        graphic_arts->closeWindow();
    }
};

//destruction
Game::~Game(){
    delete graphic_arts;
};
