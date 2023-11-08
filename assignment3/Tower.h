// Tower.h
#ifndef TOWER_H
#define TOWER_H

#include "Entity.h"
#include "Location.h"

class Tower : public Entity
{
private:
    static const char code;
    static int nextId;

public:
    Tower(const Location &loc = Location());
    static void resetId();
    void print() const; // Hides Entity::print, not override it
};

#endif // TOWER_H
