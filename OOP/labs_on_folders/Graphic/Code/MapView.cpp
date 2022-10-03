#include <SFML/Graphics.hpp>
#include "../Headlines/MapView.hpp"

//create map view
void MapView::createMapView(){
    this->map_view.reserve(this->map->getHeight());
    for (int y = 0; y < this->map->getHeight(); y++){
        this->map_view.emplace_back(std::vector <CellView*>());
        this->map_view.at(y).reserve(this->map->getWidth());
        for (int x = 0; x < this->map->getWidth(); x++){
            CellView *cl = new CellView(this->map->getCell(x, y), x, y);
            this->map_view.back().push_back(cl);
        }
    }
};

//initialization
MapView::MapView(Map* map){
    this->map = map;
    createMapView();
};

//get cell view
CellView* MapView::getCellView(int pos_x, int pos_y){
    return this->map_view.at(pos_y).at(pos_x);
};

//destruction
MapView::~MapView(){
    for (auto row: this->map_view){
        for (auto cell_view: row){
            delete cell_view;
        }
    }
};
