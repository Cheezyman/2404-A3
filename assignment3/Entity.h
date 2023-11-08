#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Location.h" // Assuming you have a Location class defined.
#include "List.h"     // Assuming you have a List class template defined.

class Entity
{
private:
    std::string id;      // Unique identifier for the entity
    Location location;   // Location of the entity
    List messageHistory; // List of pointers to messages

public:
    Entity(char typeCode, int uniqueNumber, Location loc);
    virtual ~Entity() {} // Include a virtual destructor for proper cleanup                                 // Destructor

    // Copy constructor and copy assignment operator
    Entity(const Entity &other);
    Entity &operator=(const Entity &other);

    // Move constructor and move assignment operator
    Entity(Entity &&other) noexcept;
    Entity &operator=(Entity &&other) noexcept;

    // Accessors
    const std::string &getId() const; // Get the entity's ID
    Location getLocation() const;     // Get the entity's location
    List *getMessageHistory();        // Get the message history

    // Mutators
    void addMessage(Message *m); // Add a message to the message history

    // Other functions
    int getNumMessages() const;                    // Get the number of messages
    bool equals(const std::string &otherId) const; // Compare with another entity's ID

    void print() const; // Print entity information
};

#endif // ENTITY_H
