#include "UnconditionalEvent.hpp"
#include "Player.hpp"

class FireDamageEvent: public UnconditionalEvent{
    private:
        int damage;
        Player* player;
    public:
        //initialization
        FireDamageEvent(Player* player, int damage = 25);

        //execute
        void execute() override;
};
