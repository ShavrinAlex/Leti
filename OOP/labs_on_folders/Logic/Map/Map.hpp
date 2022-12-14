#pragma once
#include "../ObserverPattern/Observable/Observable.hpp"
#include "../Entities/Entity/Entity.hpp"
#include "../Entities/Player/Player.hpp"
#include "../Cell/Cell.hpp"
#include "../Utility/Position.hpp"
#include "../Utility/Enumerations.hpp"
#include "../Controllers/EntitiesControllers/EntityController.hpp"
#include "../MediatorPattern/GameElement/GameElementDescription.hpp"
#include "../Logging/Log/Log.hpp"

#include <vector>

class GameController;

typedef std::vector < std::vector <Cell*> > CellMatrix;

typedef struct EntityElem{
    Entity* entity;
    Position* pos;
} EntityElem;

typedef std::vector <EntityElem> Enemies;

class Map: public GameElement<Log*>, public Observable{
    private:
        GameController* game_controller;

        //map
        int width, height;
        CellMatrix map;

        //win cell position
        Position win_pos;

        //player
        EntityElem* player;

        //enemies
        Enemies enemies;

        //controllers
        EntityController* player_controller;
        EntityController* enemies_controller;

        //create map
        void createMap();

        //create player elem
        void createPlayerElem();

        //convert entity position
        void convertEntityPosition(Position* position);
    public:
        //initialization
        Map();
        Map(int width, int height, Mediator<Log*>* mediator = NULL); 

        //set player
        void setPlayer(Player* player);
        void setPlayerPosition(Position* pos);

        //coping
        Map(const Map& obj);
        //assignment
        Map& operator = (const Map& obj);

        //move
        Map(Map&& obj);
        Map& operator = (Map&& obj);

        //get size
        int getHeight();
        int getWidth();

        //set game controller
        void setGameController(GameController* controller);
        GameController* getGameController();
        //set controllers
        void setControllers(EntityController* player_controller, EntityController* enemies_controller);

        //check enemy on cell
        bool isHereEnemy(int pos_x, int pos_y);
        //add enemy
        void addEnemy(Entity* enemy, Position* pos);
        //remove enemy
        void removeEnemy(Entity* enemy);
        //get enemies
        Enemies getEnemies();
        //get enemy position
        Position* getEnemyPosition(Entity* entity);

        //get player
        Entity* getPlayer();
        //get player position
        Position* getPlayerPosition();

        //check is win position
        bool isWinPosition(int pos_x, int pos_y);
        //get win position
        Position* getWinPosition();

        //get cell
        Cell* getCell(int pos_x, int pos_y);

        //calculate next entity position
        Position* calculateNextEntityPosition(Entity* entity);

        //move entity
        void moveEntity(Entity* entity);

        //make damage
        void makeDamage(Entity* entity);

        //destruction
        ~Map();
};
