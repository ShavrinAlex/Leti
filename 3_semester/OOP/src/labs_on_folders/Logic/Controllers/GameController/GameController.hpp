#pragma once
#include "../../ObserverPattern/Observer.hpp"
#include "../../GameFacadePattern/Game.hpp"
#include "../../Utility/Enumerations.hpp"
#include "../../Entities/Player/Player.hpp"

class GameController: public Observer{
    private:
        Game* game;
        Player* player;
    public:
        //initialization
        GameController(Game* game, Player* player);

        //set game status
        void setGameStatus(GameStatus status);

        //update
        void update() override;

        //destruction
        ~GameController();
};
