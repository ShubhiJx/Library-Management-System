#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    int bookID;
    string title;
    string author;
    bool available;

public:

    // Constructor
    Book(int id = 0, string t = "", string a = "")
    {
        bookID = id;
        title = t;
        author = a;
        available = true;
    }

    // Getters
    int getID()
    {
        return bookID;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    bool isAvailable()
    {
        return available;
    }

    int getStatus()
    {
        return available;
    }

    // Borrow Book
    void borrowBook()
    {
        available = false;
    }

    // Return Book
    void returnBook()
    {
        available = true;
    }

    // Display Book
    void display()
    {
        cout << "Book ID : " << bookID << endl;
        cout << "Title   : " << title << endl;
        cout << "Author  : " << author << endl;

        if (available)
            cout << "Status  : Available" << endl;
        else
            cout << "Status  : Borrowed" << endl;
    }
};

#endif