#include "../Headlines/EventGenerator.hpp"
#define FIRE "./Graphic/Images/Events/fire.png"
#define SECRET "./Graphic/Images/Events/secret.png"
#define HEALTH "./Graphic/Images/Events/health.png"
#define ARMOR "./Graphic/Images/Events/armor.png"
#define ENERGY "./Graphic/Images/Events/energy.png"
#define WIN "./Graphic/Images/Events/win.png"

//initialization
EventGenerator::EventGenerator(ConditionalEventFactory* conditional_event_factory, UnconditionalEventFactory* unconditional_event_factory, Map* map, MapView* map_view){
    this->conditional_event_factory = conditional_event_factory;
    this->unconditional_event_factory = unconditional_event_factory;
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
void EventGenerator::generateHealthEvent(){
    Position* position = this->getPositionFreeCell();

    //set health event
    (this->map->getCell(position->x, position->y))->setEvent(this->conditional_event_factory->createEvent1());

    //set health event view
    EventView* ev = new EventView(position->x, position->y, HEALTH);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set armor event and his appearance
void EventGenerator::generateArmorEvent(){
    Position* position = this->getPositionFreeCell();

    //set armor event
    (this->map->getCell(position->x, position->y))->setEvent(this->conditional_event_factory->createEvent2());

    //set armor event view
    EventView* ev = new EventView(position->x, position->y, ARMOR);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set energy event and his appearance
void EventGenerator::generateEnergyEvent(){
    Position* position = this->getPositionFreeCell();

    //set energy event
    (this->map->getCell(position->x, position->y))->setEvent(this->conditional_event_factory->createEvent3());

    //set energy event view
    EventView* ev = new EventView(position->x, position->y, ENERGY);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set fire damage event and his appearance
void EventGenerator::generateFireDamageEvent(){
    Position* position = this->getPositionFreeCell();

    //set fire damage event
    (this->map->getCell(position->x, position->y))->setEvent(this->unconditional_event_factory->createEvent1());

    //set fire damage event view
    EventView* ev = new EventView(position->x, position->y, FIRE);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set change map event and his appearance
void EventGenerator::generateChangeMapEvent(){
    Position* position = this->getPositionFreeCell();

    //set change map event
    (this->map->getCell(position->x, position->y))->setEvent(this->unconditional_event_factory->createEvent2());

    //set change map event view
    EventView* ev = new EventView(position->x, position->y, SECRET);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//generate and set win event and his appearance
void EventGenerator::generateWinEvent(){
    Position* position = this->getPositionFreeCell();

    //set win event
    (this->map->getCell(position->x, position->y))->setEvent(this->unconditional_event_factory->createEvent1());

    //set win event view
    EventView* ev = new EventView(position->x, position->y, WIN);
    (this->map_view->getCellView(position->x, position->y))->setEventView(ev);
    delete position;
};

//execute
void EventGenerator::execute(){
    this->generateHealthEvent();
    this->generateArmorEvent();
    this->generateEnergyEvent();
    this->generateFireDamageEvent();
    this->generateChangeMapEvent();
    this->generateWinEvent();
};
