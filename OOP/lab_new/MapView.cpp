#include <SFML/Graphics.hpp>
#include "MapView.hpp"

//create map view
void MapView::createMapView(CellViewMatrix& map_view){
    map_view.reserve(map->getHeight());
    for (int y = 0; y < map->getHeight(); y++){
        map_view.emplace_back(std::vector <CellView*>());
        map_view.at(y).reserve(map->getWidth());
        for (int x = 0; x < map->getWidth(); x++){
            CellView *cl = new CellView(map->getCell(x, y), x, y);
            map_view.back().push_back(cl);
        }
    }
};

//initialization
MapView::MapView(Map* map){
    this->map = map;
    createMapView(map_view);
};

//get cell view
CellView* MapView::getCellView(int pos_x, int pos_y){
    return map_view.at(pos_y).at(pos_x);
};
