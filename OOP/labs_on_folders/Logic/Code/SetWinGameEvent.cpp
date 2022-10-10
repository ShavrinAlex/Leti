#include "../Headlines/SetWinGameEvent.hpp"

//initialization
SetWinGameEvent::SetWinGameEvent(Map* map, EventFactory* factory_event_on_game, EventGenerator* event_generator):EventOnMap(map){
    this->factory_event_on_game = factory_event_on_game;
    this->event_generator = event_generator;
};

//execute
EventStatus SetWinGameEvent::execute(){
    int x, y;
    Cell* cell;
    do{;
        x = rand() % this->map->getWidth();
        y = rand() % this->map->getHeight();
        cell = this->map->getCell(x, y);
    } while(cell->getEvent() != nullptr || cell->isHerePlayer() || cell->isWall());
    Position pos = {x, y};
    this->event_generator->generateWinGameEvent(&pos, factory_event_on_game);
    return DELETE;
};
