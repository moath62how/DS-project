#include <iostream>
#include "List.h"
using namespace std;

void findBook(List lib)
{
    string title;
    cout << "Enter the title of the book you search: ";
    cin >> title;

    Book *book = lib.find(title);

    if (book != nullptr)
    {
        cout << "Book found \n";
        // display book details
    }
    else
    {
        cout << "book not found \n";
    }
}

// void ReturnBorrowedBook(string title)
// {
// }

int main()
{
    List library;
    library.add(Book("White Balance", "Moaz", 50));
    findBook(library);

    return 0;
}
