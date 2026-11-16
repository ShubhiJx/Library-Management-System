#include <iostream>
#include "Book.h"
#include "Library.h"
#include "Admin.h"
#include "Student.h"

using namespace std;

int main()
{
    Library lib;

    // Load books from file
    lib.loadBooks();

    Admin admin(1, "Admin");
    Student student(101, "Student");

    int choice;

    do
    {
        cout << "\n========== Library Management System ==========\n";
        cout << "1. Admin Login\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {

        case 1:
        {
            if(admin.login())
            {
                int adminChoice;

                do
                {
                    admin.displayUser();
                    admin.adminMenu();

                    cout << "Enter Admin Choice: ";
                    cin >> adminChoice;

                    switch(adminChoice)
                    {

                    case 1:
                    {
                        int id;
                        string title;
                        string author;

                        cout << "Enter Book ID: ";
                        cin >> id;

                        cin.ignore();

                        cout << "Enter Book Title: ";
                        getline(cin, title);

                        cout << "Enter Author Name: ";
                        getline(cin, author);

                        lib.addBook(Book(id, title, author));

                        break;
                    }

                    case 2:
                    {
                        int id;

                        cout << "Enter Book ID to Remove: ";
                        cin >> id;

                        lib.removeBook(id);

                        break;
                    }

                    case 3:
                    {
                        lib.displayBooks();
                        break;
                    }

                    case 4:
                    {
                        int id;

                        cout << "Enter Book ID to Search: ";
                        cin >> id;

                        lib.searchBook(id);

                        break;
                    }

                    case 5:
                    {
                        cout << "Logging out...\n";
                        break;
                    }

                    default:
                    {
                        cout << "Invalid Choice!\n";
                    }

                    }

                } while(adminChoice != 5);
            }

            else
            {
                cout << "Access Denied!\n";
            }

            break;
        }
                case 2:
        {
            if(student.login())
            {
                int studentChoice;

                do
                {
                    student.displayUser();
                    student.studentMenu();

                    cout << "Enter Student Choice: ";
                    cin >> studentChoice;

                    switch(studentChoice)
                    {

                    case 1:
                    {
                        lib.displayBooks();
                        break;
                    }

                    case 2:
                    {
                        int id;

                        cout << "Enter Book ID to Borrow: ";
                        cin >> id;

                        lib.borrowBook(id);

                        break;
                    }

                    case 3:
                    {
                        int id;

                        cout << "Enter Book ID to Return: ";
                        cin >> id;

                        lib.returnBook(id);

                        break;
                    }

                    case 4:
                    {
                        int id;

                        cout << "Enter Book ID to Search: ";
                        cin >> id;

                        lib.searchBook(id);

                        break;
                    }

                    case 5:
                    {
                        cout << "Logging out...\n";
                        break;
                    }

                    default:
                    {
                        cout << "Invalid Choice!\n";
                    }

                    }

                } while(studentChoice != 5);
            }

            else
            {
                cout << "Access Denied!\n";
            }

            break;
        }

        case 3:
        {
            cout << "\nThank you for using Library Management System!\n";
            break;
        }

        default:
        {
            cout << "Invalid Choice!\n";
        }

        }

    } while(choice != 3);

    return 0;
}