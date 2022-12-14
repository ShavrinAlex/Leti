#include "SetEnergyEvent.hpp"
#define MAX_ENERGY 100

//initialization
SetEnergyEvent::SetEnergyEvent(Player* player, int energy):EventOnPlayer(player){
    this->energy = energy;
};

//check conditional
bool SetEnergyEvent::checkConditional(){
    return this->player->getEnergy() != MAX_ENERGY;
};

//execute
EventStatus SetEnergyEvent::execute(){
    //check conditional
    if (this->checkConditional()){
        int player_energy = player->getEnergy() + energy;

        if (player_energy > MAX_ENERGY){
            player->setEnergy(MAX_ENERGY);
        } else{
            player->setEnergy(player_energy);
        }

        //logging
        Log* log = new Log(Processes, "Event (set energy) was execute");
        this->mediator->send(log);
        delete log;

        return Delete;
    }
    return Leave;
};
