#include <SFML/Graphics.hpp>
#include "Cell.h"
#include <vector>

typedef std::vector < std::vector <Cell*> > CellMatrix;

class Map{
    private:
        int width, height;
        CellMatrix map;
    public:
        Map();
        Map(int width, int height); 
        CellMatrix create_map();
        void draw(sf::RenderWindow *window);
        ~Map();
};
