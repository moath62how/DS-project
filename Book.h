#include <iostream>
using namespace std;

class Book
{
public:
    string title;
    string author;
    int copies;

    Book()
    {
        title = "Unknown";
        author = "Unknown";
        copies = 0;
    }

    Book(string t, string a, int c)
    {
        title = t;
        author = a;
        copies = c;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
    }
};
