#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:

    Admin(int id, string name) : User(id, name)
    {

    }

    // Admin Login
    bool login()
    {
        string username;
        string password;

        cout << "\n===== Admin Login =====" << endl;

        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        if(username == "admin" && password == "1234")
        {
            cout << "Login Successful!" << endl;
            return true;
        }
        else
        {
            cout << "Invalid Username or Password!" << endl;
            return false;
        }
    }

    // Admin Menu
    void adminMenu()
    {
        cout << "\n===== Admin Menu =====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Search Book" << endl;
        cout << "5. Logout" << endl;
    }
};

#endif