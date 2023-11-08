#ifndef CELLPHONE_H
#define CELLPHONE_H

#include "Entity.h"

class CellPhone : public Entity
{
private:
    static const char code = 'C';
    static int nextId;
    std::string number;

public:
    CellPhone(const std::string &number, const Location &loc);
    static void resetId() { nextId = 0; }
    void setLocation(const Location &loc);
    void getMessagesWith(const std::string &id, List &messages);
    void print() const override;
};

#endif // CELLPHONE_H
