#ifndef LIST_H
#define LIST_H

#include "Message.h"
#include <string>

class List
{
private:
    // Nested Node class
    class Node
    {
    public:
        Message *data;
        Node *next;

        Node(Message *msg, Node *nxt) : data(msg), next(nxt) {}
    };

    Node *head;
    Node *tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {} // Constructor
    ~List();                                          // Destructor

    // Copy constructor and copy assignment operator
    // should be defined if the class has pointer members
    List(const List &other);            // Copy constructor
    List &operator=(const List &other); // Copy assignment operator

    // Move constructor and move assignment operator
    // may also be necessary for efficient copying of List objects
    List(List &&other) noexcept;            // Move constructor
    List &operator=(List &&other) noexcept; // Move assignment operator

    void add(Message *message);    // Add message to the list
    void remove(Message *message); // Remove message from the list

    // Functions to be implemented as per your descriptions
    void getMessagesWith(const std::string &id, List &outputList) const;
    void getMessagesWith(const std::string &id1, const std::string &id2, List &outputList) const;
    void removeMessagesWith(const std::string &id, List &outputList);

    // Additional utility functions
    void print() const;                  // Print all messages
    int getSize() const { return size; } // Get the size of the list

    // More functions can be added as needed
};

#endif // LIST_H
