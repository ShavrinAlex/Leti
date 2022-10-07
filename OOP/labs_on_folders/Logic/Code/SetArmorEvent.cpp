#include "../Headlines/SetArmorEvent.hpp"

//initialization
SetArmorEvent::SetArmorEvent(Player* player){
    this->player = player;
};

//check conditional
bool SetArmorEvent::checkConditional(){
    return !this->player->getArmor();
};

//execute
void SetArmorEvent::execute(){
    if (this->checkConditional()){
        this->player->setArmor();
    }
};