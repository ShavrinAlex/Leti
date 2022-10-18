#pragma once
#include <SFML/Graphics.hpp>
#include "../Entities/Entity/Entity.hpp"
#include "../Cell/Cell.hpp"
#include "../Utility/Position.hpp"
#include "../Utility/Enumerations.hpp"
#include <vector>

typedef std::vector < std::vector <Cell*> > CellMatrix;
typedef struct Enemy{
    Entity* enemy;
    Position* pos;
} Enemy;
typedef std::vector <Enemy> Enemies;

class Map{
    private:
        Position player_position;
        int width, height;
        CellMatrix map;
        Enemies enemies;

        //create map
        void createMap();
    public:
        //initialization
        Map();
        Map(int width, int height); 

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

        //add enemy
        void addEnemy(Entity* enemy, Position* pos);

        //get enemies
        Enemies getEnemies();

        //get cell
        Cell* getCell(int pos_x, int pos_y);

        //set player position
        void setPlayerPosition(Position* next_player_position);

        //get player position
        Position* getPlayerPosition();

        //calculate next player position
        Position* calculateNextPlayerPosition(int speed, Direction direction);

        //destruction
        ~Map();
};
