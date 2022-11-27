//#include "../../../Entities/Player/Player.hpp"
//#include "../../../../Graphic/EntitiesView/PlayerView/PlayerView.hpp"
#include "../../../Map/Map.hpp"

template <int pos_x, int pos_y>
class SpawnPlayerRule{
    public:
        static void apply(Map* map);
};

template <int pos_x, int pos_y>
void SpawnPlayerRule<pos_x, pos_y>::apply(Map* map){
    Position *pos = new Position;
    pos->x = 1;
    pos->y = 1;
    map->setPlayerPosition(pos);
};
