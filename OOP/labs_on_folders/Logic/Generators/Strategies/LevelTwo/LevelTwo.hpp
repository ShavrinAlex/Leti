#pragma once
#include "../LevelStrategy.hpp"
#include "../../../MediatorPattern/Mediator.hpp"
#include "../../../Controllers/GameController/GameController.hpp"
#include "../../LevelGenerator/LevelGenerator.hpp"

#include "../../Rules/SpawnPlayerRules/SpawnPlayerRule2.hpp"
#include "../../Rules/SpawnWallsRules/SpawnWallsRule2.hpp"
#include "../../Rules/SpawnEnemiesRules/SpawnEnemiesRule2.hpp"
#include "../../Rules/SpawnEventsRules/SpawnEventsRule2.hpp"

class LevelTwo: public LevelStrategy{
    private:
        Map* map;

        LevelGenerator <SpawnWallsRule2<2123>,
                        SpawnEnemiesRule2 <517, 2>,
                        SpawnEventsRule2 <2, 2, SetHealth>,
                        SpawnEventsRule2 <1290, 2, SetArmor>,
                        SpawnEventsRule2 <122, 2, SetEnergy>,
                        SpawnEventsRule2 <54, 5, EndGame>,
                        SpawnEventsRule2 <123, 1, SetWinGame>,
                        SpawnEventsRule2 <20, 3, SetWall>,
                        SpawnPlayerRule2 <111>
                        > level_generator;
    public:
        //initialization
        LevelTwo(GameController* game_controller, Player* player, Mediator<Log*>* mediator);

        //generate level
        Map* generateLevel();
};
