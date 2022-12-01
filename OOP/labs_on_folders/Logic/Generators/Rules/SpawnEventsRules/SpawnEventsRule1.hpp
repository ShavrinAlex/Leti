#include "../../../Map/Map.hpp"
#include "../../../FactoriesPattern/EventFactory.hpp"
#include "../../../Utility/Enumerations.hpp"

#include "../../../Events/EventsOnGame/EndGameEvent/EndGameEvent.hpp"
#include "../../../Events/EventsOnGame/WinGameEvent/WinGameEvent.hpp"
#include "../../../Events/EventsOnMap/SetWallEvent/SetWallEvent.hpp"
#include "../../../Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.hpp"
#include "../../../Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.hpp"
#include "../../../Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.hpp"
#include "../../../Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.hpp"

template <int core, int precent, Events type>
class SpawnEventsRule1{
    public:
        static void apply(Map* map);
};

template <int core, int precent, Events type>
void SpawnEventsRule1<core, precent, type>::apply(Map* map){
    srand(core);
    int map_size = map->getHeight() * map->getWidth();
    
    for (int i = 0; i < (map_size / 100.0) * (precent % 100); i++){
        //generate random position
        Position* position = new Position();
        Cell* cell = nullptr;
        do{
            position->x = rand() % map->getWidth();
            position->y = rand() % map->getHeight();
            cell = map->getCell(position->x, position->y);
        } while (cell->isWall() || cell->isHerePlayer() || cell->getEvent() != nullptr);

        //set event
        Event* event;
        switch (type){
            case SetWall:
                event = new SetWallEvent(map);
                break;

            case SetWinGame:
                event = new SetWinGameEvent(map, map->getGameController());
                break;

            case WinGame:
                event = new WinGameEvent(map->getGameController());
                break;

            case EndGame:
                event = new EndGameEvent(map->getGameController());
                break;
            
            case SetHealth:
                event = new SetHealthEvent((Player*)map->getPlayer());
                break;

            case SetArmor:
                event = new SetArmorEvent((Player*)map->getPlayer());
                break;

            case SetEnergy:
                event = new SetEnergyEvent((Player*)map->getPlayer());
                break;

            default:
                break;
        }
        event->setMediator(map->getMediator());
        cell->setEvent(event);
    }
};
