#include "MapView.hpp"

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
    //logic map
    this->map = map;
    this->map->addObserver(this);

    createMapView();
};

//set player view
void MapView::setPlayerView(PlayerView* player_view){
    this->player_view = player_view;
};

//get player view
PlayerView* MapView::getPlayerView(){
    return this->player_view;
};

//add enemy view
void MapView::addEnemyView(EntityView* enemy_view){
    this->enemies_view.emplace_back(enemy_view);
};

//remove enemy view
void MapView::removeEnemyView(int index){
    auto iter = this->enemies_view.begin();
    this->enemies_view.erase(iter + index);
};

//get enemies view
EnemiesView MapView::getEnemiesView(){
    return this->enemies_view;
};

//get cell view
CellView* MapView::getCellView(int pos_x, int pos_y){
    return this->map_view.at(pos_y).at(pos_x);
};

//update
void MapView::update(){
    //update player view position
    this->player_view->setPosition(this->map->getPlayerPosition());

    //update enemies view positions
    for (size_t i = 0; i < this->enemies_view.size(); i++){
        this->enemies_view[i]->setPosition(this->map->getEnemies()[i].pos);
    }
};

//destruction
MapView::~MapView(){
    for (auto row: this->map_view){
        for (auto cell_view: row){
            delete cell_view;
        }
    }
};
