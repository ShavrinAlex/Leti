#pragma once
#include "../LevelStrategy.hpp"
#include "../../../MediatorPattern/Mediator.hpp"
#include "../../../Controllers/GameController/GameController.hpp"
#include "../../LevelGenerator/LevelGenerator.hpp"

#include "../../Rules/SpawnPlayerRules/SpawnPlayerRule1.hpp"
#include "../../Rules/SpawnWallsRules/SpawnWallsRule1.hpp"
#include "../../Rules/SpawnEnemiesRules/SpawnEnemiesRule1.hpp"
#include "../../Rules/SpawnEventsRules/SpawnEventsRule1.hpp"

class LevelOne: public LevelStrategy{
    private:
        LevelGenerator <SpawnPlayerRule1 <1, 1>,
                        SpawnWallsRule1 <123>,
                        SpawnEnemiesRule1 <1, 5>,
                        SpawnEventsRule1 <2, 5, SetHealth>,
                        SpawnEventsRule1 <2, 5, SetArmor>,
                        SpawnEventsRule1 <2, 5, SetEnergy>,
                        SpawnEventsRule1 <2, 5, EndGame>,
                        SpawnEventsRule1 <2, 1, SetWinGame>,
                        SpawnEventsRule1 <2, 3, SetWall>
                        > level_generator;
    public:
        //initialization
        LevelOne(GameController* game_controller, Player* player, Mediator<Log*>* mediator, int map_height, int map_width);

        //generate level
        Map* generateLevel();
};
