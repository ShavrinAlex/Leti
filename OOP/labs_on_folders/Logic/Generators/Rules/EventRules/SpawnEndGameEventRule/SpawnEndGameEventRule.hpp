#include "../../../../Map/Map.hpp"
#include "../../../../../Graphic/MapView/MapView.hpp"
#include "../../../MediatorPattern/Mediator.hpp"
#include "../../../FactoriesPattern/EventFactory.hpp"

template <int magic_number1, int magic_number2>
class SpawnEndGameRule{
    private:
        Position* getPositionFreeCell(Map* map);
    public:
        static void apply(Map* map, MapView* map_view, EventFactory* factory);
};

//get position random free cell
template <int magic_number1, int magic_number2>
Position* SpawnEndGameRule<magic_number1, magic_number2>::getPositionFreeCell(Map* map){
    Position* position = new Position();
    Cell* cell = nullptr;
    do{
        position->x = rand() % this->map->getWidth();
        position->y = rand() % this->map->getHeight();
        cell = this->map->getCell(position->x, position->y);
    } while (cell->isWall() || cell->getEvent() != nullptr || cell->isHerePlayer() || this->map->isHereEnemy(position));
    return position;
}

template <int magic_number1, int magic_number2>
void SpawnEndGameRule<magic_number1, magic_number2>::apply(Map* map, MapView* map_view, EventFactory* factory){
    for (int i = 0; i < (map_size / 100.0) * magic_number1; i++){
        Position* position = this->getPositionFreeCell(map);

        //set end game event
        (map->getCell(position->x, position->y))->setEvent(factory->createEvent2());

        //set end game event view
        EventView* ev = new EventView(position->x, position->y, FIRE);
        (map_view->getCellView(position->x, position->y))->setEventView(ev);
        
        delete position;
    }
};