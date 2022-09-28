#include "Mediator.hpp"
#include "CommandReader.hpp"
#include "Player.hpp"
#include "EntityView.hpp"
#include "Map.hpp"
#include "Enumerations.hpp"
#include <ctime>

class Controller: public Mediator{
    private:
        Player* player;
        Map* map;
        EntityView* player_view;
        CommandReader* com_reader;
        int time;
        int timer;
    public:
        //initialization
        Controller(Player* player, Map* map, EntityView* player_view, CommandReader* com_reader);

        //send
        void send(std::string message, GameElement* element);

        //move player
        void movePlayer(Direction dir);
};
