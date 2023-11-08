#ifndef NETWORK_H
#define NETWORK_H

#include "Tower.h"
#include "CellPhone.h"
#include <vector>

class Network
{
private:
    std::vector<CellPhone *> cellPhones;
    std::vector<Tower *> towers;

public:
    Network();
    void addCellPhone(const std::string &number, const Location &loc);
    void addTower(const Location &loc);
    void routeMessage(const Message &message);
    void moveCellPhone(const std::string &id, const Location &loc);
    void getMessageHistory(const std::string &id, const List **messages);
    void getMessagesWith(const std::string &id1, const std::string &id2, List &outputList);
    void resetIds();
    void printTowers() const;
    void printCellPhones() const;

    // Helper functions
private:
    Tower *findClosestTower(const Location &loc);
    Entity *getEntityById(const std::string &id);
};

#endif // NETWORK_H
