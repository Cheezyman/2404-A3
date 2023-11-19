#ifndef LIST_H
#define LIST_H

#include "Message.h"
#include <string>

class List
{
public:
    List();
    ~List();

    bool isEmpty() const;
    int getSize() const;
    Message *removeFirst();
    void add(Message *message);
    void print() const;
    void getMessagesWith(const std::string &id, List &outputList);
    void getMessagesWith(const std::string &id1, const std::string &id2, List &outputList);
    void removeMessagesWith(const std::string &id, List &outputList);

private:
    // Private nested Node class
    class Node
    {
    public:
        Message *data;
        Node *next;
        Node *prev;
        Node(Message *message) : data(message), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;
};

#endif // LIST_H
