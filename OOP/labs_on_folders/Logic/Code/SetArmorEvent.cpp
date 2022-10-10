#include "../Headlines/SetArmorEvent.hpp"

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
        return DELETE;
    }
    return LEAVE;
};