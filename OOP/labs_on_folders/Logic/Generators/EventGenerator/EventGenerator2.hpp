#include "../../Map/Map.hpp"
#include "../../../Graphic/MapView/MapView.hpp"
#include "../../MediatorPattern/Mediator.hpp"
#include "../../FactoriesPattern/EventFactory.hpp"

template <typename ... Rules>
class EventGenerator{
public:
    void applyRules(Map *map, MapView *map_view, EventFactory* factory);
};


template <typename ... Rules>
void EventGenerator<Rules ...>::applyRules(Map *map, MapView *map_view, EventFactory* factory){
    (Rules::apply(map, map_view, EventFactory* factory), ...);
};