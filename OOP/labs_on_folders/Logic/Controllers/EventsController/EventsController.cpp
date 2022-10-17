#include "EventsController.hpp"
#include <iostream>
//initialization
EventsController::EventsController(EventGenerator* event_generator, FactoryEventOnPlayer* factory_event_on_player, FactoryEventOnGame* factory_event_on_game, FactoryEventOnMap* factory_event_on_map, int map_height, int map_width){
    this->event_generator = event_generator;

    this->factory_event_on_game = factory_event_on_game;
    this->factory_event_on_map = factory_event_on_map;
    this->factory_event_on_player = factory_event_on_player;
    this->map_size = map_height * map_width;

    //set win game event
    event_generator->generateSetWinGameEvent(factory_event_on_map);
};

//update events
void EventsController::createEvents(){
    //create end game events 
    for (int i = 0; i < (this->map_size / 100.0) * 5; i++){
        event_generator->generateEndGameEvent(factory_event_on_game);
    }

    //create set wall events 
    for (int i = 0; i < (this->map_size / 100.0) * 8; i++){
        event_generator->generateSetWallEvent(factory_event_on_map);
    }

    //create set health events 
    for (int i = 0; i < (this->map_size / 100.0) * 5; i++){
        event_generator->generateHealthEvent(factory_event_on_player);
    }

    //create set armor events 
    for (int i = 0; i < (this->map_size / 100.0) * 3; i++){
        event_generator->generateArmorEvent(factory_event_on_player);
    }
    
    //create set energy events 
    for (int i = 0; i < (this->map_size / 100.0) * 8; i++){
        event_generator->generateEnergyEvent(factory_event_on_player);
    }
};

//destruction
EventsController::~EventsController(){
    this->event_generator = nullptr;

    this->factory_event_on_game = nullptr;
    this->factory_event_on_map = nullptr;
    this->factory_event_on_player = nullptr;
};
