#include "Entity.h"
#include <iostream>

// Constructor
Entity::Entity(char code, int num, Location loc)
    : id(code + to_string(num)), location(loc) {}

// Accessor for the entity's message history
List *Entity::getMessageHistory()
{
    return &messageHistory;
}

// Accessor for the entity's location
Location Entity::getLocation() const
{
    return location;
}

// Add a message to the message history
void Entity::addMessage(const Message &m)
{
    // Create a copy of 'm' on the heap.
    Message *messageCopy = new Message(m);

    messageHistory.add(messageCopy);
}

// Get the number of messages
int Entity::getNumMessages() const
{
    return messageHistory.getSize(); // Assuming 'getSize' returns the number of elements
}

// Compare with another entity's ID
bool Entity::equals(const std::string &otherId) const
{
    return id == otherId;
}

// Print entity information
void Entity::print() const
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Location: ";
    location.print(); // Assuming Location class has a print method
    std::cout << "Number of Messages: " << getNumMessages() << std::endl;
}