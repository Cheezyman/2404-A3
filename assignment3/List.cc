#include "List.h"
#include <iostream>

// good
List::List() : head(nullptr), tail(nullptr), size(0) {}

// good
List::~List()
{
    while (!isEmpty())
    {
        removeFirst();
    }
}

// managing nodes in linked list

// good
bool List::isEmpty() const
{
    return head == nullptr;
}

// good
int List::getSize() const
{
    return size;
}

Message *List::removeFirst()
{
    if (size = 0)
    {
        return nullptr;
    }
    Node *temp = head;
    Message *message = temp->data;

    if (head->next == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        delete head;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
    return message;
}

// good
void List::add(Message *message)
{
    Node *newNode = new Node(message);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// good
void List::print() const
{
    Node *current = head;
    while (current != nullptr)
    {
        current->data->print();
        current = current->next;
    }
}

// Accessing info form linked list

// good
void List::getMessagesWith(const std::string &id, List &outputList)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data->getSender() == id || current->data->getReceiver() == id)
        {
            outputList.add(current->data);
        }
        current = current->next;
    }
}

// good
void List::getMessagesWith(const std::string &id1, const std::string &id2, List &outputList)
{
    Node *current = head;
    while (current != nullptr)
    {
        if ((current->data->getSender() == id1 && current->data->getReceiver() == id2) ||
            (current->data->getSender() == id2 && current->data->getReceiver() == id1))
        {
            outputList.add(current->data);
        }
        current = current->next;
    }
}

// good
void List::removeMessagesWith(const std::string &id, List &outputList)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;

        if (current->data->getSender() == id || current->data->getReceiver() == id)
        {
            outputList.add(current->data);

            if (current == head)
            {
                head = nextNode;
                if (head)
                    head->prev = nullptr;
            }
            else
            {
                current->prev->next = nextNode;
            }

            if (current == tail)
            {
                tail = current->prev;
                if (tail)
                    tail->next = nullptr;
            }
            else
            {
                nextNode->prev = current->prev;
            }

            delete current;
            size--;
        }

        current = nextNode;
    }

    if (head == nullptr)
        tail = nullptr;
}
