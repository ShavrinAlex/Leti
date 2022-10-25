#include "Game.hpp"
#include "../Entities/Player/Player.hpp"
#include "../../Graphic/EntitiesView/PlayerView/PlayerView.hpp"
#include "../CommandReader/CommandReader.hpp"
#include "../Utility/Enumerations.hpp"
#include "../StartDialog/StartDialog.hpp"
#include "../Controllers/EntitiesControllers/EnemiesController/EnemiesController.hpp"
#include "../MediatorPattern/CommandReaderMediator/CommandReaderMediator.hpp"
#include "../FactoriesPattern/FactoryEventOnPlayer/FactoryEventOnPlayer.hpp"
#include "../FactoriesPattern/FactoryEventOnMap/FactoryEventOnMap.hpp"
#include "../FactoriesPattern/FactoryEventOnGame/FactoryEventOnGame.hpp"
#include "../Generators/EventGenerator/EventGenerator.hpp"
#include "../Generators/EnemyGenerator/EnemyGenerator.hpp"
#define PLAYER_W 98
#define PLAYER_H 98
#define START_POSITION {1, 1}
#define PLAYER_IMAGE "./Graphic/Images/Entities/Player/hero1.png"
#include <iostream>

//initialization
Game::Game(){
    //create log controller and mediator
    this->log_controller = new LogController();
    this->mediator = new LogMediator(log_controller);

    StartDialog start_dialog = StartDialog(this->mediator);
    this->map_width = start_dialog.getWidth();
    this->map_height = start_dialog.getHeight();
    this->graphic_arts = new GraphicArts(this->map_width, this->map_height);
    this->game_status = Continues;
};

//game start
int Game::startGame(){
    //logging
    Log* log = new Log(GameStates, "Game was started");
    this->mediator->send(log);
    delete log;
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

    //create command reader
    CommandReader com_reader = CommandReader();

    //create player
    Player player = Player();
    player.setSpeed(1);
    player.setDamage(50);
    //player.setMediator(&log_mediator);

    //create map
    Map map = Map(this->map_width, this->map_height, this->mediator);
    map.setPlayer(&player);

    //create map view
    MapView map_view = MapView(&map);

    //create player view
    PlayerView player_view = PlayerView(&player, PLAYER_W, PLAYER_H, map.getPlayerPosition(), PLAYER_IMAGE);

    //create player and game controllers
    GameController game_controller = GameController(this, &player);
    PlayerController player_controller = PlayerController(&player, &map, &player_view);
    player_controller.setMediator(this->mediator);

    //create command reader mediator
    CommandReaderMediator com_reader_mediator = CommandReaderMediator(&player_controller, &game_controller, log_controller);

    //set command reader mediator
    com_reader.setMediator(&com_reader_mediator);

    //create event generator
    EventGenerator event_generator = EventGenerator(&map, &map_view);
    event_generator.setMediator(this->mediator);

    //create event fabrics
    FactoryEventOnPlayer factory_event_on_player = FactoryEventOnPlayer(&player);
    FactoryEventOnGame factory_event_on_game = FactoryEventOnGame(&game_controller);
    FactoryEventOnMap factory_event_on_map = FactoryEventOnMap(&map, &factory_event_on_game, &event_generator);

    //create events
    event_generator.setFactories(&factory_event_on_player, &factory_event_on_game, &factory_event_on_map);
    event_generator.generate(this->map_height, this->map_width);

    //create enemy generator
    EnemyGenerator enemy_generator = EnemyGenerator(&map, &map_view);
    enemy_generator.generate(this->map_height, this->map_width);

    //create enemies controller
    EnemiesController enemies_controller = EnemiesController(&map, &map_view);

    //set player and enemies controllers on map
    map.setControllers(&player_controller, &enemies_controller);

    //main loop
    while (graphic_arts->isOpen() && this->game_status == Continues){
        //check close window
        this->graphic_arts->pollEvent();
        
        //player actions
        com_reader.getPressedKey();

        //enemies actions
        enemies_controller.move();
    
        //draw all
        this->graphic_arts->clear();
        this->graphic_arts->drawMap(map_view);
        this->graphic_arts->drawPlayer(player_view);
        this->graphic_arts->display();
    }

    //logging
    log = new Log(GameStates, "Game was end");
    this->mediator->send(log);
    delete log;

    return 0;
};

//set game status
void Game::setGameStatus(GameStatus game_status){
    this->game_status = game_status;
};

//destruction
Game::~Game(){
    delete graphic_arts;
};
