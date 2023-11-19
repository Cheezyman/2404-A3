#ifndef CELLPHONE_H
#define CELLPHONE_H

#include "Entity.h"
#include <string>
#include <list>

// Forward declaration to avoid include
class Message;

class CellPhone : public Entity
{
private:
    static const char code; // Prefix 'C' for CellPhone id
    static int nextId;      // To produce the next unique number for id

    std::string number; // Phone number of the CellPhone

public:
    // Constructor declaration
    CellPhone(std::string number, const Location &loc = Location());

    // Static function to reset the nextId
    static void resetId();

    // Setter for Location
    void setLocation(const Location &loc);

    // Function to get messages with a certain id
    void getMessagesWith(const std::string &id, List &messages);

    // Override the print function
    void print() const;

    // Destructor
    ~CellPhone();
};

#endif // CELLPHONE_H
