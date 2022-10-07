#include "UnconditionalEvent.hpp"
#include "Map.hpp"

class ChangeMapEvent: public UnconditionalEvent{
    private:
        Map* map;
    public:
        //initialization
        ChangeMapEvent(Map* map);

        //execute
        void execute() override;
};
