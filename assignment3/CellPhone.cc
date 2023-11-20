#include "CellPhone.h"

// Initialize static members
const char CellPhone::code = 'C';
int CellPhone::nextId = 1;

// Constructor implementation
CellPhone::CellPhone(std::string number, const Location &loc)
    : Entity(CellPhone::code, nextId++, loc), number(number)
{
}

// resetId static member function implementation
void CellPhone::resetId()
{
    nextId = 1;
}

// setLocation member function implementation
void CellPhone::setLocation(const Location &loc)
{
    location = loc;
}

//  getMessagesWith member function implementation
void CellPhone::getMessagesWith(const std::string &id, List &messages)
{
    getMessageHistory()->List::getMessagesWith(id, messages);
}

void CellPhone::getMessagesWith(const std::string &id1, const std::string &id2, List &messages)
{
    getMessageHistory()->List::getMessagesWith(id1, id2, messages);
}
// print override function implementation
void CellPhone::print() const
{
    Entity::print();                                      // Calls base class print to print ID, location, and number of messages
    std::cout << "Phone Number: " << number << std::endl; // Prints the phone number
}