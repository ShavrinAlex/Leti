#include "MapView.hpp"
#include "../../Logic/Events/Event.hpp"
#include "../../Logic/Events/EventsOnGame/EndGameEvent/EndGameEvent.hpp"
#include "../../Logic/Events/EventsOnGame/WinGameEvent/WinGameEvent.hpp"
#include "../../Logic/Events/EventsOnMap/SetWallEvent/SetWallEvent.hpp"
#include "../../Logic/Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.hpp"
#include "../../Logic/Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.hpp"
#include "../../Logic/Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.hpp"
#include "../../Logic/Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.hpp"
#define FIRE "./Graphic/Images/Events/EventsOnGame//fire.png"
#define WIN "./Graphic/Images/Events/EventsOnGame/win.png"
#define SECRET "./Graphic/Images/Events/EventsOnMap/secret.png"
#define HEALTH "./Graphic/Images/Events/EventsOnPlayer/health.png"
#define ARMOR "./Graphic/Images/Events/EventsOnPlayer/armor.png"
#define ENERGY "./Graphic/Images/Events/EventsOnPlayer/energy.png"
#define PLAYER_W 98
#define PLAYER_H 98
#define PLAYER_IMAGE "./Graphic/Images/Entities/Player/hero1.png"
#define ENEMY_WIDTH 98
#define ENEMY_HEIGHT 98
#define ENEMY_IMAGE "./Graphic/Images/Entities/Player/hero1.png"

//create map view
void MapView::createMapView(){
    this->map_view.reserve(this->map->getHeight());
    for (int y = 0; y < this->map->getHeight(); y++){
        this->map_view.emplace_back(std::vector <CellView*>());
        this->map_view.at(y).reserve(this->map->getWidth());
        for (int x = 0; x < this->map->getWidth(); x++){
            CellView *cl = new CellView(this->map->getCell(x, y), x, y);
            this->map_view.back().push_back(cl);

            Event* event = this->map->getCell(x, y)->getEvent();
            if (event != nullptr){
                this->map_view.at(y).at(x)->setEventView(this->createEventView(event, x, y));
            }
        }
    }
};

//create enemies view
void MapView::createEnemiesView(){
    for(auto enemy_elem: this->map->getEnemies()){
        EntityView* ev = new EntityView(enemy_elem.entity, ENEMY_WIDTH, ENEMY_HEIGHT, enemy_elem.pos, ENEMY_IMAGE);
        this->addEnemyView(ev);
    }
};

//create player view
void MapView::createPlayerView(){
    PlayerView* player_view = new PlayerView(static_cast<Player*>(this->map->getPlayer()), PLAYER_W, PLAYER_H, this->map->getPlayerPosition(), PLAYER_IMAGE);
    this->setPlayerView(player_view);
};

//create event view
EventView* MapView::createEventView(Event* event, int x, int y){
    EventView* event_view;
    if (dynamic_cast<EndGameEvent*>(event)){
        event_view = new EventView(x, y, FIRE);
    }
    if (dynamic_cast<WinGameEvent*>(event)){
        event_view = new EventView(x, y, WIN);
    }
    if (dynamic_cast<SetWinGameEvent*>(event) || dynamic_cast<SetWallEvent*>(event)){
        event_view = new EventView(x, y, SECRET);
    }
    if (dynamic_cast<SetArmorEvent*>(event)){
        event_view = new EventView(x, y, ARMOR);
    }
    if (dynamic_cast<SetHealthEvent*>(event)){
        event_view = new EventView(x, y, HEALTH);
    }
    if (dynamic_cast<SetEnergyEvent*>(event)){
        event_view = new EventView(x, y, ENERGY);
    }
    return event_view;
};

//initialization
MapView::MapView(Map* map){
    //logic map
    this->map = map;
    this->map->addObserver(this);

    createMapView();
    createPlayerView();
    createEnemiesView();
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
    delete this->enemies_view.at(index);

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

//update player position
void MapView::updatePlayerPosition(){
    //update player view position
    this->player_view->setPosition(this->map->getPlayerPosition());
};

//update count enemies
void MapView::updateCountEnemies(){
    bool is_remove = false;

    if (this->map->getEnemies().size() != this->enemies_view.size()){
        //check last enemy view
        if (this->map->getEnemies().size() == 0 && this->enemies_view.size() != 0){
            this->removeEnemyView(0);
            return;
        }

        //check all enemy without end
        for (size_t i = 0; i < this->map->getEnemies().size(); i++){
            if (this->enemies_view.at(i)->getLogicEntity() != this->map->getEnemies().at(i).entity){
                this->removeEnemyView(i);
                is_remove = true;
                break;
            }
        }

        //remove end enemy
        if (is_remove == false && this->enemies_view.size() > this->map->getEnemies().size()){
            this->removeEnemyView(this->enemies_view.size()-1);
        }
    }
};

//update enemies positions
void MapView::updateEnemiesPositions(){
    //update enemies view positions
    for (size_t i = 0; i < this->enemies_view.size(); i++){
        this->enemies_view[i]->setPosition(this->map->getEnemies()[i].pos);
    }
};

//update events
void MapView::updateEvents(){
    for (int y = 0; y < this->map->getHeight(); y++){
        for (int x = 0; x < this->map->getWidth(); x++){
            Event* event = this->map->getCell(x, y)->getEvent();

            if (event != nullptr && this->getCellView(x, y)->getEventView() == nullptr){
                this->getCellView(x, y)->setEventView(this->createEventView(event, x, y));
            }
        }
    }
};

//update
void MapView::update(){
    this->updatePlayerPosition();
    this->updateCountEnemies();
    this->updateEnemiesPositions();
    this->updateEvents();
};

//destruction
MapView::~MapView(){
    for (auto row: this->map_view){
        for (auto cell_view: row){
            delete cell_view;
        }
    }
};
