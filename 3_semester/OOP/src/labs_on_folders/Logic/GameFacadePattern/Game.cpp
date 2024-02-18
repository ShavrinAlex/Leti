#include "Game.hpp"
#include "../Entities/Player/Player.hpp"
#include "../../Graphic/EntitiesView/PlayerView/PlayerView.hpp"
#include "../CommandReader/KeyboardCommandReader/KeyboardCommandReader.hpp"
#include "../Utility/Enumerations.hpp"
#include "../StartDialogs/StartLevelDialog/StartLevelDialog.hpp"
#include "../Controllers/EntitiesControllers/EnemiesController/EnemiesController.hpp"
#include "../MediatorPattern/CommandReaderMediator/CommandReaderMediator.hpp"
#include "../Generators/EventGenerator/EventGenerator.hpp"
#include "../Generators/EnemyGenerator/EnemyGenerator.hpp"
#include "../CommandReader/CommandAdapterPattern/CommandAdapter.hpp"
#include "../Generators/Strategies/LevelOne/LevelOne.hpp"
#include "../Generators/Strategies/LevelTwo/LevelTwo.hpp"
#include "../Generators/Strategies/LevelContext/LevelContext.hpp"
#define PLAYER_W 98
#define PLAYER_H 98
#define PLAYER_IMAGE "./Graphic/Images/Entities/Player/hero1.png"
#include <iostream>

//initialization
Game::Game(){
    //create log controller and mediator
    this->log_controller = new LogController();
    this->mediator = new LogMediator(log_controller);

    StartLevelDialog start_level_dialog = StartLevelDialog();
    start_level_dialog.setMediator(mediator);
    start_level_dialog.executor();

    this->map_width = start_level_dialog.getWidth();
    this->map_height = start_level_dialog.getHeight();
    this->level = start_level_dialog.getLevel();
    
    this->graphic_arts = new GraphicArts(this->map_width, this->map_height);
    this->game_status = Continues;
};

//crreate level
Map* Game::createLevel(GameController* game_controller, Player* player){
    //create level
    LevelContext level_context = LevelContext();
    switch (this->level){
        case One:
            level_context.setStrategy(new LevelOne(game_controller, player, this->mediator, this->map_height, this->map_width));
            break;
        case Two:
            level_context.setStrategy(new LevelTwo(game_controller, player, this->mediator, this->map_height, this->map_width));
            break;
    }
    return level_context.createLevel();
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

    //create player and game controllers
    GameController game_controller = GameController(this, &player);

    //create level
    Map* map = this->createLevel(&game_controller, &player);

    //create player controller
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
