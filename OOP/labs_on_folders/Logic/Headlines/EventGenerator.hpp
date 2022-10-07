#pragma once
#include "ConditionalEventFactory.hpp"
#include "UnconditionalEventFactory.hpp"
#include "Map.hpp"
#include "../../Graphic/Headlines/MapView.hpp"

class EventGenerator{
    private:
        ConditionalEventFactory* conditional_event_factory;
        UnconditionalEventFactory* unconditional_event_factory;
        Map* map;
        MapView* map_view;
    public:
        //initialization
        EventGenerator(ConditionalEventFactory* conditional_event_factory, UnconditionalEventFactory* unconditional_event_factory, Map* map, MapView* map_view);

        //get position random free cell
        Position* getPositionFreeCell();

        //generate and set health event and his appearance
        void generateHealthEvent();

        //generate and set armor event and his appearance
        void generateArmorEvent();

        //generate and set energy event and his appearance
        void generateEnergyEvent();

        //generate and set fire damage event and his appearance
        void generateFireDamageEvent();

        //generate and set change map event and his appearance
        void generateChangeMapEvent();

        //generate and set win event and his appearance
        void generateWinEvent();

        //execute
        void execute();
};
