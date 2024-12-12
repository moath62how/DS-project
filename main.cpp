#include <bits/stdc++.h>
#include "List.h"
using namespace std;

List library;

void fileSystemLoad();
void fileSystemSave();
void greeting();
void printChoiceMenu();
void getChoice();
void findBook();
void BorrowBook();
void returnBorrowedBook();
void addBook();
void displayBooks();
void removeBook();

int main()
{
    fileSystemLoad();
    greeting();
    getChoice();
    fileSystemSave();
    return 0;
}

void displayBooks()
{
    cout << "-- Books in the Library --" << endl;
    library.print();
    cout << "--------------------------------" << endl;
}

void greeting()
{
    string message = "Welcome to the library!";
    cout << message << endl;
}

void printChoiceMenu()
{
    cout << "\nLibrary Menu:\n";
    cout << "1. Display Books\n";
    cout << "2. Add Book\n";
    cout << "3. Remove Book\n";
    cout << "4. Find Book\n";
    cout << "5. Borrow Book\n";
    cout << "6. Return Book\n";
    cout << "7. Exit\n";
}
void getChoice()
{
    unsigned int choice;
    do
    {
        printChoiceMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayBooks();
            break;
        case 2:
            addBook();
            break;
        case 3:
            removeBook();
            break;
        case 4:
            findBook();
            break;
        case 5:
            BorrowBook();
            break;
        case 6:
            returnBorrowedBook();
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);
}

void addBook()
{
    string title, author;
    int copies;
    cout << "Enter the title of Book: ";
    cin.ignore(); // To clear the buffer before getline
    getline(cin, title);
    cout << "Enter the author of Book: ";
    getline(cin, author);
    cout << "Enter the copies of Book: ";
    cin >> copies;
    library.add(Book(title, author, copies));
}

void removeBook()
{
    string title;
    cout << "Enter the title of the book to remove: ";
    cin.ignore(); // To clear the buffer before getline
    getline(cin, title);

    Book *book = library.find(title);

    if (book != nullptr)
    {
        library.remove(title);
        cout << "Book removed successfully.\n";
    }
    else
    {
        cout << "Error: Book not found in the library.\n";
    }
}

void findBook()
{
    string title;
    cout << "Enter the title of the book you search: ";
    cin.ignore(); // To clear the buffer before getline
    getline(cin, title);

    Book *book = library.find(title);

    if (book != nullptr)
    {
        cout << "Book found \n";
        book->display();
    }
    else
    {
        cout << "Book not found \n";
    }
}

void BorrowBook()
{
    cout << "Enter the title of the book that you want to borrow: ";
    string title;
    cin.ignore(); // To clear the buffer before getline
    getline(cin, title);

    Book *book = library.find(title);

    if (book != nullptr)
    {
        if (book->copies > 0)
        {
            book->copies--;
            cout << "You have borrowed the book: " << book->title << endl;
            cout << "Remaining copies: " << book->copies << endl;
        }
        else
        {
            cout << "Sorry, no copies available to borrow.\n";
        }
    }
    else
    {
        cout << "Book not found \n";
    }
}

void returnBorrowedBook()
{
    cout << "Enter the title of the book that you want to return: ";
    string title;
    cin.ignore(); // To clear the buffer before getline
    getline(cin, title);

    Book *book = library.find(title);

    if (book != nullptr)
    {
        book->copies++;
        cout << "Book returned successfully." << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void fileSystemLoad()
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

void fileSystemSave()
{
    ofstream outputFile("./DATA.txt", ios::trunc);

    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to save to DATA.txt " << endl;
        return;
    }

    Node *current = library.getHead();
    while (current != nullptr)
    {
        Book &book = current->data;
        outputFile << book.title << "," << book.author << "," << book.copies << endl;
        current = current->next;
    }

    outputFile.close();
    cout << "Library data saved successfully." << endl;
}
