#include "EventGenerator.hpp"
#define FIRE "./Graphic/Images/Events/EventsOnGame//fire.png"
#define WIN "./Graphic/Images/Events/EventsOnGame/win.png"
#define SECRET "./Graphic/Images/Events/EventsOnMap/secret.png"
#define HEALTH "./Graphic/Images/Events/EventsOnPlayer/health.png"
#define ARMOR "./Graphic/Images/Events/EventsOnPlayer/armor.png"
#define ENERGY "./Graphic/Images/Events/EventsOnPlayer/energy.png"

//initialization
EventGenerator::EventGenerator(Map* map, MapView* map_view){
    this->map = map;
    this->map_view = map_view;
};

//get position random free cell
Position* EventGenerator::getPositionFreeCell(){
    Position* position = new Position();
    Cell* cell = nullptr;
    do{
        position->x = rand() % this->map->getWidth();
        position->y = rand() % this->map->getHeight();
        cell = this->map->getCell(position->x, position->y);
    } while (cell->isWall() || cell->isHerePlayer() || cell->getEvent() != nullptr);
    return position;
}

//generate and set health event and his appearance
void EventGenerator::generateHealthEvent(EventFactory* factory_event_on_player){
    Position* position = this->getPositionFreeCell();

    //set health event
    (this->map->getCell(position->x, position->y))->setEvent(factory_event_on_player->createEvent1());

    //set health event view
    EventView* ev = new EventView(position->x, position->y, HEALTH);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set armor event and his appearance
void EventGenerator::generateArmorEvent(EventFactory* factory_event_on_player){
    Position* position = this->getPositionFreeCell();

    //set armor event
    (this->map->getCell(position->x, position->y))->setEvent(factory_event_on_player->createEvent2());

    //set armor event view
    EventView* ev = new EventView(position->x, position->y, ARMOR);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set energy event and his appearance
void EventGenerator::generateEnergyEvent(EventFactory* factory_event_on_player){
    Position* position = this->getPositionFreeCell();

    //set energy event
    (this->map->getCell(position->x, position->y))->setEvent(factory_event_on_player->createEvent3());

    //set energy event view
    EventView* ev = new EventView(position->x, position->y, ENERGY);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set win game event and his appearance
void EventGenerator::generateWinGameEvent(Position* position, EventFactory* factory_event_on_game){
    //set win event
    (this->map->getCell(position->x, position->y))->setEvent(factory_event_on_game->createEvent1());

    //set win event view
    EventView* ev = new EventView(position->x, position->y, WIN);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
};

//generate and set end game event and his appearance
void EventGenerator::generateEndGameEvent(EventFactory* factory_event_on_game){
    Position* position = this->getPositionFreeCell();

    //set end game event
    (this->map->getCell(position->x, position->y))->setEvent(factory_event_on_game->createEvent2());

    //set end game event view
    EventView* ev = new EventView(position->x, position->y, FIRE);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
};

//generate and set wall event and his appearance
void EventGenerator::generateSetWallEvent(EventFactory* factory_event_on_map){
    Position* position = this->getPositionFreeCell();

    //set change map event
    (this->map->getCell(position->x, position->y))->setEvent(factory_event_on_map->createEvent1());

    //set change map event view
    EventView* ev = new EventView(position->x, position->y, SECRET);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set SetWinGameEvent and his appearance
void EventGenerator::generateSetWinGameEvent(EventFactory* factory_event_on_map){
    Position* position = this->getPositionFreeCell();

    //set SetWinGameEvent
    (this->map->getCell(position->x, position->y))->setEvent(factory_event_on_map->createEvent2());

    //set SetWinGameEvent view
    EventView* ev = new EventView(position->x, position->y, SECRET);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
};

//destruction
EventGenerator::~EventGenerator(){
    this->map = nullptr;
    this->map_view = nullptr;
};
