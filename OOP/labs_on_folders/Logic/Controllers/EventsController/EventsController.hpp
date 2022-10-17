#include "../../EventGenerator/EventGenerator.hpp"
#include "../../FactoriesPattern/FactoryEventOnPlayer/FactoryEventOnPlayer.hpp"
#include "../../FactoriesPattern/FactoryEventOnMap/FactoryEventOnMap.hpp"
#include "../../FactoriesPattern/FactoryEventOnGame/FactoryEventOnGame.hpp"

class EventsController{
    private:
        EventGenerator* event_generator;
        FactoryEventOnPlayer* factory_event_on_player;
        FactoryEventOnGame* factory_event_on_game;
        FactoryEventOnMap* factory_event_on_map;

        int map_size;
    public:
        //initialization
        EventsController(EventGenerator* event_generator, FactoryEventOnPlayer* factory_event_on_player, FactoryEventOnGame* factory_event_on_game, FactoryEventOnMap* factory_event_on_map, int map_height, int map_width);

        //update
        void createEvents();

        //destruction
        ~EventsController();
};
