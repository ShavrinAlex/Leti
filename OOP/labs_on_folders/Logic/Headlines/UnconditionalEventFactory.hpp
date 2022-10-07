#pragma once
#include "EventFactory.hpp"
#include "Player.hpp"
#include "Map.hpp"
class Game;

class UnconditionalEventFactory: public EventFactory{
    private:
        Player* player;
        Map* map;
        Game* game;
    public:
        //initialization
        UnconditionalEventFactory(Player* player, Map* map, Game* game);

        //create events
        Event* createEvent1();
        Event* createEvent2();
        Event* createEvent3();
};