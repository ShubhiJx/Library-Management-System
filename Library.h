#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Book.h"

using namespace std;

class Library
{
private:
    vector<Book> books;

public:

    // Load books from file
    void loadBooks()
    {
        books.clear();

        ifstream file("books.txt");

        if(!file)
        {
            cout << "No existing file found. Starting new library." << endl;
            return;
        }

        int id;
        string title;
        string author;
        int status;

        while(file >> id)
        {
            file.ignore();

            getline(file, title);

            getline(file, author);

            file >> status;
            file.ignore();

            Book b(id, title, author);

            if(status == 0)
                b.borrowBook();

            books.push_back(b);
        }

        file.close();

        cout << "Books loaded successfully!" << endl;
    }


    // Save books into file
    void saveBooks()
    {
        ofstream file("books.txt");

        for(Book b : books)
        {
            file << b.getID() << endl;
            file << b.getTitle() << endl;
            file << b.getAuthor() << endl;
            file << b.getStatus() << endl;
        }

        file.close();
    }


    // Add Book
    void addBook(Book b)
    {
        books.push_back(b);

        saveBooks();

        cout << "Book added successfully!" << endl;
    }


    // Display Books
    void displayBooks()
    {
        if(books.empty())
        {
            cout << "No books available!" << endl;
            return;
        }

        for(Book b : books)
        {
            b.display();
            cout << "------------------------" << endl;
        }
    }


    // Search Book
    void searchBook(int id)
    {
        for(Book b : books)
        {
            if(b.getID() == id)
            {
                cout << "Book Found!" << endl;
                b.display();
                return;
            }
        }

        cout << "Book not found!" << endl;
    }


    // Remove Book
    void removeBook(int id)
    {
        for(auto it = books.begin(); it != books.end(); it++)
        {
            if(it->getID() == id)
            {
                books.erase(it);

                saveBooks();

                cout << "Book removed successfully!" << endl;
                return;
            }
        }

        cout << "Book not found!" << endl;
    }


    // Borrow Book
    void borrowBook(int id)
    {
        for(auto &b : books)
        {
            if(b.getID() == id)
            {
                if(b.isAvailable())
                {
                    b.borrowBook();

                    saveBooks();

                    cout << "Book borrowed successfully!" << endl;
                }
                else
                {
                    cout << "Book is already borrowed!" << endl;
                }

                return;
            }
        }

        cout << "Book not found!" << endl;
    }


    // Return Book
    void returnBook(int id)
    {
        for(auto &b : books)
        {
            if(b.getID() == id)
            {
                if(!b.isAvailable())
                {
                    b.returnBook();

                    saveBooks();

                    cout << "Book returned successfully!" << endl;
                }
                else
                {
                    cout << "Book is already available!" << endl;
                }

                return;
            }
        }

        cout << "Book not found!" << endl;
    }

};

#endif