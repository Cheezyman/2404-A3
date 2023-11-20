// Message.cpp
#include "Message.h"
#include <iostream>

// Constructor
Message::Message(const std::string &sender, const std::string &receiver, const std::string &message)
    : sender(sender), receiver(receiver), message(message) {}

// Getter for the sender
std::string Message::getSender() const
{
    return sender;
}

// Getter for the receiver
std::string Message::getReceiver() const
{
    return receiver;
}

// Print function
void Message::print() const
{
    std::cout << "From: " << sender << std::endl;
    std::cout << "To: " << receiver << std::endl;
    std::cout << "Message: " << message << std::endl;
}