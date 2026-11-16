#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User
{
public:

    Student(int id, string name) : User(id, name)
    {

    }

    // Student Login
    bool login()
    {
        int studentID;
        string password;

        cout << "\n===== Student Login =====" << endl;

        cout << "Enter Student ID: ";
        cin >> studentID;

        cout << "Enter Password: ";
        cin >> password;

        if(studentID == 101 && password == "student123")
        {
            cout << "Login Successful!" << endl;
            return true;
        }
        else
        {
            cout << "Invalid Student ID or Password!" << endl;
            return false;
        }
    }

    // Student Menu
    void studentMenu()
    {
        cout << "\n===== Student Menu =====" << endl;
        cout << "1. View Books" << endl;
        cout << "2. Borrow Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Search Book" << endl;
        cout << "5. Logout" << endl;
    }

};

#endif