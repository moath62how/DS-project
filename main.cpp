#include <bits/stdc++.h>
#include "List.h"
using namespace std;

void findBook(List &lib)
{
    string title;
    cout << "Enter the title of the book you search: ";
    getline(cin, title);

    Book *book = lib.find(title);

    if (book != nullptr)
    {
        cout << "Book found \n";
        book->display();
    }
    else
    {
        cout << "book not found \n";
    }
}

void BorrowBook(List &lib)
{
    cout << "Enter the title of the book that you want to borrow: ";
    string title;
    getline(cin, title);

    Book *book = lib.find(title);

    if (book != nullptr)
    {
        if (book->copies > 0)
        {
            book->copies--;
            cout << "you have borrowed the boook: " << book->title << endl;
            cout << "Remaining copies: " << book->copies << endl;
        }
        else
        {
            cout << "Sorry, no copies available to borrow.\n";
        }
    }
    else
    {
        cout << "book not found \n";
    }
}

void returnBorrowedBook(List &lib);

void fileSystem(List &library);
int main()
{
    List library;
    library.print();
    exit(0);
    return 0;
}

void returnBorrowedBook(List &lib)
{
    cout << "Enter the title of the book that you want to Return: ";
    string title;
    getline(cin, title);
    cout << title << endl;
    Book *book = lib.find(title);

    if (book != nullptr)
    {
        book->copies++;
        cout << "Book returned succsesfuly." << endl;
    }
    else
    {
        cout << "book not found" << endl;
    }
}

void fileSystem(List &library)
{
    ifstream inputFile("./DATA.txt");

    if (!inputFile.is_open())
    {
        cout << "Current working directory: " << filesystem::current_path() << endl;
        cerr << "Error: Unable to open DATA.txt " << endl;
        exit(1);
    }

    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string title, author;
        int copies;

        getline(ss, title, ',');
        getline(ss, author, ',');
        ss >> copies;

        library.add(Book(title, author, copies));
    }
    inputFile.close();
}