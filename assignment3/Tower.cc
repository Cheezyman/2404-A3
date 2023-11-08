// Tower.cpp
#include "Tower.h"
#include <iostream>

const char Tower::code = 'T';
int Tower::nextId = 0;

Tower::Tower(const Location &loc)
    : Entity(Tower::code, nextId++, loc)
{
    // nextId is passed and then incremented for the next Tower
}

void Tower::resetId()
{
    Tower::nextId = 0;
}

void Tower::print() const
{
    // Prints information about the Tower, specifically.
    // Since we're not using virtual functions, this just hides Entity::print.
    std::cout << "Tower - ID: " << this->getId() << ", Location: " << this->getLocation() << std::endl;
}

// You can add other member functions or logic as needed for your Tower class here.
