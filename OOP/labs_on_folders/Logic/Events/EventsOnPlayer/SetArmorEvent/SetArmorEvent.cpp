#include "SetArmorEvent.hpp"

//initialization
SetArmorEvent::SetArmorEvent(Player* player):EventOnPlayer(player){};

//check conditional
bool SetArmorEvent::checkConditional(){
    return !this->player->getArmor();
};

//execute
EventStatus SetArmorEvent::execute(){
    if (this->checkConditional()){
        this->player->setArmor();

        //logging
        Log* log = new Log(Processes, "Set armor event was execute");
        this->mediator->send(log);
        delete log;

        return Delete;
    }
    return Leave;
};