#include "Game.hpp"
#include "../Entities/Player/Player.hpp"
#include "../../Graphic/EntitiesView/PlayerView/PlayerView.hpp"
#include "../CommandReader/KeyboardCommandReader/KeyboardCommandReader.hpp"
#include "../Utility/Enumerations.hpp"
#include "../StartDialogs/StartMapSizeDialog/StartMapSizeDialog.hpp"
#include "../Controllers/EntitiesControllers/EnemiesController/EnemiesController.hpp"
#include "../MediatorPattern/CommandReaderMediator/CommandReaderMediator.hpp"
#include "../Generators/EventGenerator/EventGenerator.hpp"
#include "../Generators/EnemyGenerator/EnemyGenerator.hpp"
#include "../CommandReader/CommandAdapterPattern/CommandAdapter.hpp"
#include "../Generators/Strategies/LevelOne/LevelOne.hpp"
#include "../Generators/Strategies/LevelTwo/LevelTwo.hpp"
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

    StartMapSizeDialog start_map_size_dialog = StartMapSizeDialog(this->mediator);
    start_map_size_dialog.executor();

    this->map_width = start_map_size_dialog.getWidth();
    this->map_height = start_map_size_dialog.getHeight();
    
    this->graphic_arts = new GraphicArts(this->map_width, this->map_height);
    this->game_status = Continues;
};

//game start
int Game::startGame(){
    //logging
    Log* log = new Log(GameStates, "Game started");
    this->mediator->send(log);
    delete log;
    
    //create player
    Player player = Player();
    player.setSpeed(1);
    player.setDamage(50);

/*
    //create map
    Map map = Map(this->map_width, this->map_height, this->mediator);
    map.setPlayer(&player);
    Position *pos = new Position;
    pos->x = 1;
    pos->y = 1;
    map.setPlayerPosition(pos);
    */
    //create player and game controllers
    GameController game_controller = GameController(this, &player);
    /*
    LevelOne level = LevelOne(&game_controller, &player, this->mediator);
    Map* map = level.generateLevel();
    std::cout<<"level created\n";
    */
    LevelTwo level = LevelTwo(&game_controller, &player, this->mediator);
    Map* map = level.generateLevel();
    std::cout<<"level created\n";

    PlayerController player_controller = PlayerController(&player, map);
    player_controller.setMediator(this->mediator);

    //create command reader mediator
    CommandReaderMediator com_reader_mediator = CommandReaderMediator(&player_controller, &game_controller, log_controller);
    //create keyboard command adapter
    CommandAdapter com_adapter = CommandAdapter(this->mediator);
    //create keyboard command reader
    KeyboardCommandReader com_reader = KeyboardCommandReader(&com_adapter);
    //set command reader mediator
    com_reader.setMediator(&com_reader_mediator);
/*
    //create event generator
    EventGenerator event_generator = EventGenerator(map);

    //create event fabrics
    FactoryEventOnPlayer factory_event_on_player = FactoryEventOnPlayer(&player);
    factory_event_on_player.setMediator(this->mediator);
    FactoryEventOnGame factory_event_on_game = FactoryEventOnGame(&game_controller);
    factory_event_on_game.setMediator(this->mediator);
    FactoryEventOnMap factory_event_on_map = FactoryEventOnMap(&map, &factory_event_on_game);
    factory_event_on_map.setMediator(this->mediator);

    //create events
    event_generator.setFactories(&factory_event_on_player, &factory_event_on_game, &factory_event_on_map);
    event_generator.generate(this->map_height, this->map_width);

    //create enemy generator
    EnemyGenerator enemy_generator = EnemyGenerator(map);
    enemy_generator.generate(this->map_height, this->map_width);
*/
    //create map view
    MapView map_view = MapView(map);
    
    //create enemies controller
    EnemiesController enemies_controller = EnemiesController(map);

    //set player and enemies controllers on map
    map->setControllers(&player_controller, &enemies_controller);

    //main loop
    while (graphic_arts->isOpen() && (this->game_status == Continues || this->game_status == Pause)){
        if (this->game_status == Continues){
            //player actions
            com_reader.readCommand((this->graphic_arts)->pollEvent());

            //enemies actions
            enemies_controller.move();
        
            //draw all
            this->graphic_arts->clear();
            this->graphic_arts->drawMap(map_view);
            this->graphic_arts->display();
        }
    }
    //logging
    log = new Log(GameStates, "Game ended");
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
