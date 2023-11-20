#include "Network.h"
#include <iostream>
#include <algorithm>
#include <limits>

// Constructor
Network::Network() {}

// Destructor
Network::~Network()
{
    for (auto phone : cellPhones)
    {
        delete phone;
    }
    for (auto tower : towers)
    {
        delete tower;
    }
}

// Add a CellPhone
void Network::addCellPhone(const std::string &number, const Location &location)
{
    CellPhone *newPhone = new CellPhone(number, location);
    cellPhones.push_back(newPhone);
}

// Add a Tower
void Network::addTower(const Location &location)
{
    Tower *newTower = new Tower(location);
    towers.push_back(newTower);
}

// Route a message
void Network::routeMessage(const Message &message)
{
    CellPhone *sender = findCellPhone(message.getSender());
    CellPhone *receiver = findCellPhone(message.getReceiver());

    if (!sender || !receiver)
    {
        std::cout << "Message routing failed: Sender or receiver not found." << std::endl;
        return;
    }

    sender->addMessage(message);
    receiver->addMessage(message);

    Tower *closestToSender = findClosestTower(sender->getLocation());
    Tower *closestToReceiver = findClosestTower(receiver->getLocation());

    if (closestToSender)
    {
        closestToSender->addMessage(message);
    }
    if (closestToReceiver && closestToSender != closestToReceiver)
    {
        closestToReceiver->addMessage(message);
    }
}

// Move a CellPhone
void Network::moveCellPhone(const std::string &id, const Location &location)
{
    CellPhone *phone = findCellPhone(id);
    if (phone)
    {
        phone->setLocation(location);
    }
    else
    {
        std::cout << "CellPhone with ID " << id << " not found." << std::endl;
    }
}

// Get Message History
bool Network::getMessageHistory(const std::string &id, const List **messages)
{
    Entity *entity = findCellPhone(id);
    if (!entity)
    {
        entity = findTower(id);
    }

    if (entity)
    {
        *messages = entity->getMessageHistory();
        return true;
    }
    else
    {
        std::cout << "No entity found with ID " << id << std::endl;
        return false;
    }
}

// Get Messages Between Two IDs
void Network::getMessagesWith(const std::string &id1, const std::string &id2, List &outputList)
{
    for (auto phone : cellPhones)
    {
        if (phone->equals(id1) || phone->equals(id1))
        {
            phone->getMessagesWith(id1, id2, outputList);
            break;
        }
    }
}

// Reset IDs
void Network::resetIds()
{
    CellPhone::resetId();
    Tower::resetId();
}

// Print Towers
void Network::printTowers() const
{
    for (const auto &tower : towers)
    {
        tower->print();
    }
}

// Print CellPhones
void Network::printCellPhones() const
{
    for (const auto &phone : cellPhones)
    {
        phone->print();
    }
}

// Helper functions
Tower *Network::findClosestTower(const Location &location)
{
    Tower *closest = nullptr;
    int minDistance = std::numeric_limits<int>::max();

    for (auto tower : towers)
    {
        int distance = location.getDistance(tower->getLocation());
        if (distance < minDistance)
        {
            minDistance = distance;
            closest = tower;
        }
    }

    return closest;
}

CellPhone *Network::findCellPhone(const std::string &id)
{
    for (auto phone : cellPhones)
    {
        if (phone->equals(id))
        {
            return phone;
        }
    }
    return nullptr;
}

Tower *Network::findTower(const std::string &id)
{
    for (auto tower : towers)
    {
        if (tower->equals(id))
        {
            return tower;
        }
    }
    return nullptr;
}
