// Message.h
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
private:
    std::string sender;   // The ID of the sender
    std::string receiver; // The ID of the receiver
    std::string message;  // The content of the message

public:
    // Constructor
    Message(const std::string &sender, const std::string &receiver, const std::string &message);

    // Getter for the sender
    std::string getSender() const;

    // Getter for the receiver
    std::string getReceiver() const;

    // Print function
    void print() const;
};

#endif // MESSAGE_H
