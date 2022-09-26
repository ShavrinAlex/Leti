#include "Map.hpp"
#include "CellView.hpp"
#include <vector>

typedef std::vector <std::vector <CellView*>> CellViewMatrix;

class MapView{
    private:
        Map* map;
        CellViewMatrix map_view;

        //create map view
        void createMapView(CellViewMatrix& map_view);
        
    public:
        //initialization
        MapView(Map* map);

        //get cell view
        CellView* getCellView(int pos_x, int pos_y);
};
