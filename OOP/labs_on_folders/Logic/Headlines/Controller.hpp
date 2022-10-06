#include "Mediator.hpp"
#include "CommandReader.hpp"
#include "Player.hpp"
#include "../../Graphic/Headlines/EntityView.hpp"
#include "../../Graphic/Headlines/PlayerView.hpp"
#include "Map.hpp"
#include "Enumerations.hpp"
#include "SFML/Graphics.hpp"

class Controller: public Mediator{
    private:
        Player* player;
        Map* map;
        PlayerView* player_view;
        CommandReader* com_reader;
        sf::Clock clock;
        float time;
        float timer;
    public:
        //initialization
        Controller(Player* player, Map* map, PlayerView* player_view, CommandReader* com_reader);

        //send
        void send(std::string message, GameElement* element);

        //move player
        void movePlayer(Direction dir);
};
