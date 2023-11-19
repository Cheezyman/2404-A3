#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "CellPhone.h"
#include "Tower.h"

class Network
{
private:
    std::vector<CellPhone *> cellPhones;
    std::vector<Tower *> towers;

    // Helper functions
    Tower *findClosestTower(const Location &location);
    CellPhone *findCellPhone(const std::string &id);
    Tower *findTower(const std::string &id);

public:
    // Constructor
    Network();

    // Destructor
    ~Network();

    // Member functions
    void addCellPhone(const std::string &number, const Location &location);
    void addTower(const Location &location);
    void routeMessage(const Message &message);
    void moveCellPhone(const std::string &id, const Location &location);
    void getMessageHistory(const std::string &id, const List **messages);
    void getMessagesWith(const std::string &id1, const std::string &id2, List &outputList);
    void resetIds();
    void printTowers() const;
    void printCellPhones() const;
};

#endif // NETWORK_H
