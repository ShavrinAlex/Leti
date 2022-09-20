#pragma once
#include "Position.h"

class StartDialog{
    private:
        int start_height;
        int start_width;
        bool is_size_set;
        Position player_position;
        bool is_player_position_set;

    public:
        //initialization
        StartDialog();

        //executor
        void executor();

        //map
        bool isSizeSet();
        int getHeight();
        int getWidth();

        //player
        bool isPlayerPositionSet();
        Position getPlayerPosition();
};
