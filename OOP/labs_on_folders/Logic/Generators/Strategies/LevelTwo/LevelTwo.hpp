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

        LevelGenerator <SpawnPlayerRule2 <111>,
                        SpawnWallsRule2 <123>,
                        SpawnEnemiesRule2 <233, 2>,
                        SpawnEventsRule2 <1, 2, SetHealth>,
                        SpawnEventsRule2 <1, 2, SetArmor>,
                        SpawnEventsRule2 <1, 2, SetEnergy>,
                        SpawnEventsRule2 <1, 2, EndGame>,
                        SpawnEventsRule2 <1, 2, SetWall>,
                        SpawnEventsRule2 <1, 2, SetWinGame>
                        > level_generator;
    public:
        //initialization
        LevelTwo(GameController* game_controller, Player* player, Mediator<Log*>* mediator);

        //generate level
        Map* generateLevel();
};
