#include "Entity.h"
#include <iostream>

// Constructor
Entity::Entity(char typeCode, int uniqueNumber, Location loc) : location(loc)
{
    id = std::string(1, typeCode) + std::to_string(uniqueNumber);
}

// Destructor
Entity::~Entity()
{
    // Assuming List class manages the memory of the messages
    // If it doesn't, you need to delete each message here.
}

// Copy constructor
Entity::Entity(const Entity &other)
    : id(other.id), location(other.location), messageHistory(other.messageHistory)
{
    // Deep copy of messageHistory if required
}

// Copy assignment operator
Entity &Entity::operator=(const Entity &other)
{
    if (this != &other)
    {
        id = other.id;
        location = other.location;
        messageHistory = other.messageHistory; // Deep copy of messageHistory if required
    }
    return *this;
}

// Move constructor
Entity::Entity(Entity &&other) noexcept
    : id(std::move(other.id)), location(std::move(other.location)), messageHistory(std::move(other.messageHistory)) {}

// Move assignment operator
Entity &Entity::operator=(Entity &&other) noexcept
{
    if (this != &other)
    {
        id = std::move(other.id);
        location = std::move(other.location);
        messageHistory = std::move(other.messageHistory);
    }
    return *this;
}

// Accessor for the entity's ID
const std::string &Entity::getId() const
{
    return id;
}

// Accessor for the entity's location
Location Entity::getLocation() const
{
    return location;
}

// Accessor for the entity's message history
List *Entity::getMessageHistory()
{
    return &messageHistory;
}

// Add a message to the message history
void Entity::addMessage(Message *m)
{
    messageHistory.add(m);
}

// Get the number of messages
int Entity::getNumMessages() const
{
    return messageHistory.getSize();
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
    location.print();
    // Assuming that the List class has an implementation to handle printing of its elements
    messageHistory.print();
}
