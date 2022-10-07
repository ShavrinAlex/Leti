#pragma once

class Event{
    public:
        void virtual execute() = 0;
        virtual ~Event(){};
};
