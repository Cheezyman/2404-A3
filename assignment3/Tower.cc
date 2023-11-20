// Tower.cpp
#include "Tower.h"
#include <iostream>

const char Tower::code = 'T';
int Tower::nextId = 1;

Tower::Tower(const Location &loc)
    : Entity(Tower::code, nextId++, loc)
{
}

void Tower::resetId()
{
    Tower::nextId = 1;
}

void Tower::print() const
{
    // Prints information about the Tower, specifically.
    std::cout << "Tower - ID: " << id << ", Location: ";
    getLocation().print();
    std::cout << "Number of Messages: " << getNumMessages() << std::endl;
}
