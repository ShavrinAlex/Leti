#pragma once
#include "../Generator/Generator.hpp"
#include "../../FactoriesPattern/EventFactory.hpp"
#include "../../FactoriesPattern/FactoryEventOnGame/FactoryEventOnGame.hpp"
#include "../../FactoriesPattern/FactoryEventOnMap/FactoryEventOnMap.hpp"
#include "../../FactoriesPattern/FactoryEventOnPlayer/FactoryEventOnPlayer.hpp"

class EventGenerator: public Generator{
    private:
        FactoryEventOnPlayer* factory_event_on_player;
        FactoryEventOnGame* factory_event_on_game;
        FactoryEventOnMap* factory_event_on_map;
        Mediator<Log*>* mediator;
    public:
        //initialization
        EventGenerator(Map* map, MapView* map_view, Mediator<Log*>* mediator);

        //set factories
        void setFactories(FactoryEventOnPlayer* factory_event_on_player, FactoryEventOnGame* factory_event_on_game, FactoryEventOnMap* factory_event_on_map);

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

        //generate all events
        void generate(int map_height, int map_width) override;

        //destruction
        ~EventGenerator();
};
