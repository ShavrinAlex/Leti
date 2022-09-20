#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Position.h"
#include <vector>

typedef std::vector < std::vector <Cell*>* > CellMatrix;

class Map{
    private:
        Position player_position;
        int width, height;
        CellMatrix *map;
    public:
        //initialization
        Map();
        Map(int width, int height); 

        //get size
        int getHeight();
        int getWidth();

        //create map
        CellMatrix* create_map();

        //get map
        CellMatrix* get_map();

        //get cell
        Cell* getCell(int pos_x, int pos_y);

        //set player position
        void setPlayerPosition(Position next_player_position);

        //get player position
        Position getPlayerPosition();

        //move player on next cell
        void movePlayer(Position next_player_position);
        /*
        //draw map
        void draw(sf::RenderWindow *window);
        */
        //update
        void update();

        //destructor
        ~Map();
};
