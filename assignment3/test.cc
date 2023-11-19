#include <iostream>
#include <string>
#include <sstream>

#include "CellPhone.h"
#include "Tower.h"
#include "Tester.h"

#define ARR 5

using namespace std;

extern string messageText[9];
extern string numbers[ARR];


int towerIdTest();
int cellPhoneIdTest();
int messageTest();

int main(){

  
    int choice = 0;
    cout << endl;
    cout << "What test would you like to run?"<< endl;
    cout << "  (0) Tower id test." << endl;
    cout << "  (1) CellPhone id test." << endl;
    cout << "  (2) Message test." << endl;
    cout << endl;

    cin >> choice;
    switch(choice){
      case 0: return towerIdTest();
      case 1: return cellPhoneIdTest(); 
      case 2: return messageTest(); 
    }

    return 1;
}

// make some Towers and check their id number
int towerIdTest(){
    cout<<"This test will print out 5 towers and verify their id numbers."<<endl<<endl;
    vector<int> keys = {4,0,1,3,2};
    string strs[ARR] = {"T5","T1","T2","T4", "T3"}; 
    Tower* towers[ARR];
    for (int i = 0; i < ARR; ++i){
      towers[i] = new Tower(Location());
    }

    Tester tester;

    tester.initCapture();
    for (int i = 0; i < ARR; ++i){
        towers[keys[i]]->print();
    }
    tester.endCapture();

    int error = 0;
    tester.findInOrder({0,1,2,3,4}, strs, error);

    if (error>0){
      cout << "At least one id not found in order, or not found at all" << endl;
      return 1;
    }

    return 0;
}

// make some cellPhones and check their id number
int cellPhoneIdTest(){
    cout<<"This test will print out 5 cellphones and verify their id numbers."<<endl<<endl;
    vector<int> keys = {4,0,1,3,2};
    string strs[ARR] = {"C5","C1","C2","C4","C3"}; 
    CellPhone* cellPhones[ARR];
    for (int i = 0; i < ARR; ++i){
      cellPhones[i] = new CellPhone(numbers[i], Location());
    }

    Tester tester;

    tester.initCapture();
    for (int i = 0; i < ARR; ++i){
        cellPhones[keys[i]]->print();
    }
    tester.endCapture();

    int error = 0;
    tester.findInOrder({0,1,2,3,4}, strs, error);

    if (error>0){
      cout << "At least one id not found in order, or not found at all" << endl;
      return 1;
    }

    tester.findInOrder(keys, numbers, error);

    if (error>0){
      cout << "At least one phone number not found in order, or not found at all" << endl;
      return 1;
    }
    return 0;
}

int messageTest(){
    CellPhone *c = new CellPhone("Elsa", Location(3, 4));
    Tower *t = new Tower(Location(1, 1));

    cout<<"This will add 3 messages to the tower and cellphone, then print them out."<<endl<<endl;

    string strs[9] = {"C1","C2","Hello Kyle", "C2", "C1", "Hello Elsa","C1", "C3", "Hello Bonnie"}; 

    if (c->getNumMessages() != 0 || t->getNumMessages() != 0)
    {
        cout << "CellPhone or Tower does not have 0 messages to start, test failed!" << endl;
        return 1;
    }

    cout << endl
         << "Adding 3 messages..." << endl;
    t->addMessage(Message("C1", "C2", "Hello Kyle"));
    t->addMessage(Message("C2", "C1", "Hello Elsa"));
    t->addMessage(Message("C1", "C3", "Hello Bonnie"));

    Tester tester;

    tester.initCapture();
    t->getMessageHistory()->print();
    tester.endCapture();
    int error = 0;
    vector<int> keys = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    tester.findInOrder(keys, strs, error);

    if (error>0){
      cout << "At least one message not found in order, or not found at all" << endl;
      return 1;
    }
    cout<<"All tower messages found (in order)"<<endl<<endl;

    cout<<"Adding 3 messages to cellphone..."<<endl;
    c->addMessage(Message("C1", "C2", "Hello Kyle"));
    c->addMessage(Message("C2", "C1", "Hello Elsa"));
    c->addMessage(Message("C1", "C3", "Hello Bonnie"));

    tester.initCapture();
    c->getMessageHistory()->print();
    tester.endCapture();
    tester.findInOrder(keys, strs, error);

    if (error>0){
      cout << "At least one message not found in order, or not found at all" << endl;
      return 1;
    }

    cout<<"All cellphone messages found (in order)"<<endl<<endl;
    return 0;
}

string numbers[ARR] = {"(123) 456-7890", "(234) 567-8901", "(345) 678-9012", "(456) 789-0123", "(567) 890-1234"};


string messageText[9] = {
    "C1: Hello C1", "C1: Hello C2", "C1: Hello C3", 
    "C2: Hello C1", "C2: Hello C2", "C2: Hello C3", 
    "C3: Hello C1", "C3: Hello C2", "C3: Hello C3"};
