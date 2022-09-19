#include <SFML/Graphics.hpp>
#include "Cell.h"
#include <vector>

typedef std::vector < std::vector <Cell*>* > CellMatrix;

class Map{
    private:
        int width, height;
        CellMatrix *map;
    public:
        //initialization
        Map();
        Map(int width, int height); 

        //create map
        CellMatrix* create_map();

        //draw map
        void draw(sf::RenderWindow *window);

        //update
        void update(Player *hero);

        //destructor
        ~Map();
};
