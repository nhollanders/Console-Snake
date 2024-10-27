#ifndef _player_obj
#define _player_obj

#include "Vec2d.h"

class player_obj {
    private:
        Vec2d playerPos; // cur pos
        Vec2d nextPos; // next pos

        int moveDist; // how far each move goes
    public:
        player_obj();
        ~player_obj();

        void setPos(Vec2d vecPar);
        Vec2d getPos();

        void setMoveDist(int dist);
        int getMoveDist();

        Vec2d getNextPos(); // returns the position its planning to move to next
        bool posChanged(); // whether the position has changed or not in the last input update

        void updateInput(); // run in a while loop and it will take inputs from defined keys
        void move(); // changes the position of the object to the planned position
};

#endif