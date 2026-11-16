#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    int userID;
    string name;

public:

    // Constructor
    User(int id, string n)
    {
        userID = id;
        name = n;
    }

    // Display User Information
    void displayUser()
    {
        cout << "\nUser ID : " << userID << endl;
        cout << "Name    : " << name << endl;
    }
};

#endif