#pragma once
#include "../FactoriesPattern/EventFactory.hpp"
#include "../Map/Map.hpp"
#include "../../Graphic/MapView/MapView.hpp"

class EventGenerator{
    private:
        Map* map;
        MapView* map_view;
    public:
        //initialization
        EventGenerator(Map* map, MapView* map_view);

        //get position random free cell
        Position* getPositionFreeCell();

        //generate and set health event and his appearance
        void generateHealthEvent(EventFactory* factory_event_on_player);

        //generate and set armor event and his appearance
        void generateArmorEvent(EventFactory* factory_event_on_player);

        //generate and set energy event and his appearance
        void generateEnergyEvent(EventFactory* factory_event_on_player);

        //generate and set win game event and his appearance
        void generateWinGameEvent(Position* position, EventFactory* factory_event_on_game);

        //generate and set end game event and his appearance
        void generateEndGameEvent(EventFactory* factory_event_on_game);

        //generate and set wall event event and his appearance
        void generateSetWallEvent(EventFactory* factory_event_on_map);

        //generate and set wall event and his appearance
        void generateSetWinGameEvent(EventFactory* factory_event_on_map);

        //destruction
        ~EventGenerator();
};
