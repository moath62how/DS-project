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

int main()
{
    Book book1;
    book1.display();

    Book book2("The Great Gatsby", "F. Scott Fitzgerald", 5);
    book2.display();

    return 0;
}
