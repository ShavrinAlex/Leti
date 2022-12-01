#include "../../../Map/Map.hpp"
#include "../../../Utility/Enumerations.hpp"

#include "../../../Events/EventsOnGame/EndGameEvent/EndGameEvent.hpp"
#include "../../../Events/EventsOnGame/WinGameEvent/WinGameEvent.hpp"
#include "../../../Events/EventsOnMap/SetWallEvent/SetWallEvent.hpp"
#include "../../../Events/EventsOnMap/SetWinGameEvent/SetWinGameEvent.hpp"
#include "../../../Events/EventsOnPlayer/SetArmorEvent/SetArmorEvent.hpp"
#include "../../../Events/EventsOnPlayer/SetEnergyEvent/SetEnergyEvent.hpp"
#include "../../../Events/EventsOnPlayer/SetHealthEvent/SetHealthEvent.hpp"

template <int magic_number, int count, Events type>
class SpawnEventsRule2{
    public:
        static void apply(Map* map);
};

template <int magic_number, int count, Events type>
void SpawnEventsRule2<magic_number, count, type>::apply(Map* map){
    Position* position = new Position();
    Cell* cell = nullptr;

    for (int i = 1; i <= count; i++){
        int tmp_number = magic_number;
        //generate position
        do {
            position->x = tmp_number * i % map->getWidth();
            position->y = tmp_number * i % map->getHeight();
            cell = map->getCell(position->x, position->y);
            tmp_number++;
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
    std::cout<<"end\n";
};