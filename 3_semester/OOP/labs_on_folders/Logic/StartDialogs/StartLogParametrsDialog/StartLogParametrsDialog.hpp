#pragma once
#include "../../Utility/Enumerations.hpp"
#include "../../Controllers/LogController/LogController.hpp"

class StartLogParametrDialog{
    private:
        bool is_levels_set;
        bool is_streams_set;

        LogController* log_controller;

        //convert user requests
        int convertLevel(char user_level);
        int convertStreams(std::string user_streams);

        //user dialog
        int userDialog();
    public:
        //initialization
        StartLogParametrDialog(LogController* log_controller);

        //executor
        void executor();

        //destruction
        ~StartLogParametrDialog();
};
