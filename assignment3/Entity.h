#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Location.h" // Assuming you have a Location class defined.
#include "List.h"     // Assuming you have a List class template defined.

class Entity
{
private:
    List messageHistory; // List of pointers to messages

protected:
    std::string id;    // Unique identifier for the entity
    Location location; // Location of the entity

public:
    Entity(char code, int num, Location loc);
    ~Entity();
    List *getMessageHistory();    // Get the message history
    Location getLocation() const; // Get the entity's location

    // Mutators
    void addMessage(const Message &); // Add a message to the message history

    // Other functions
    int getNumMessages() const;                    // Get the number of messages
    bool equals(const std::string &otherId) const; // Compare with another entity's ID

    void print() const; // Print entity information
};

#endif // ENTITY_H
