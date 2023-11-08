#include "List.h"
#include <iostream>

// Destructor
List::~List()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current->data; // Assuming ownership of messages
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

// Copy constructor
List::List(const List &other) : head(nullptr), tail(nullptr), size(0)
{
    Node *current = other.head;
    while (current != nullptr)
    {
        add(new Message(*(current->data))); // Deep copy of the message
        current = current->next;
    }
}

// Copy assignment operator
List &List::operator=(const List &other)
{
    if (this != &other)
    {
        List temp(other);
        std::swap(head, temp.head);
        std::swap(tail, temp.tail);
        std::swap(size, temp.size);
    }
    return *this;
}

// Move constructor
List::List(List &&other) noexcept
    : head(other.head), tail(other.tail), size(other.size)
{
    other.head = other.tail = nullptr;
    other.size = 0;
}

// Move assignment operator
List &List::operator=(List &&other) noexcept
{
    if (this != &other)
    {
        delete this;
        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

// Add message to the list
void List::add(Message *message)
{
    Node *newNode = new Node(message, nullptr);
    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    else
    {
        head = newNode;
    }
    tail = newNode;
    ++size;
}

// Print all messages
void List::print() const
{
    Node *current = head;
    while (current != nullptr)
    {
        current->data->print();
        current = current->next;
    }
}

void List::getMessagesWith(const std::string &id, List &outputList) const
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data->getSender() == id || current->data->getReceiver() == id)
        {
            outputList.add(new Message(*(current->data))); // Add a copy of the Message
        }
        current = current->next;
    }
}

void List::getMessagesWith(const std::string &id1, const std::string &id2, List &outputList) const
{
    Node *current = head;
    while (current != nullptr)
    {
        bool isSenderReceiverMatch = (current->data->getSender() == id1 && current->data->getReceiver() == id2);
        bool isReceiverSenderMatch = (current->data->getSender() == id2 && current->data->getReceiver() == id1);

        if (isSenderReceiverMatch || isReceiverSenderMatch)
        {
            outputList.add(new Message(*(current->data))); // Add a copy of the Message
        }
        current = current->next;
    }
}

void List::removeMessagesWith(const std::string &id, List &outputList)
{
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        bool isSenderOrReceiverMatch = (current->data->getSender() == id || current->data->getReceiver() == id);

        if (isSenderOrReceiverMatch)
        {
            // Save the message to be removed
            Message *toRemove = current->data;

            // Re-link nodes
            if (prev == nullptr)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // If we're at the end, update tail
            if (tail == current)
            {
                tail = prev;
            }

            Node *next = current->next;
            delete current; // Delete the current node
            current = next; // Move to next node
            size--;

            outputList.add(toRemove); // Add the message to the outputList
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    if (size == 0)
    {
        tail = nullptr; // Ensure the tail is nullptr if list is empty
    }
}