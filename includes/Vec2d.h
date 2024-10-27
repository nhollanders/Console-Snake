#ifndef _Vec2d
#define _Vec2d

struct Vec2d
{
    int x;
    int y;

    bool operator==(const Vec2d& other) const { // adds a return for the equal operator
        return (x == other.x && y == other.y);
    }
    
    bool operator!=(const Vec2d& other) const { // adds a return for the not equal operator
        return (x != other.x || y != other.y);
    }
};

#endif