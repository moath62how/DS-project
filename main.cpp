#include <iostream>
#include <List.h>
using namespace std;

void FindBook(List lib) {
    string title;
    cout << "Enter the title of the book you search: ";
    cin.ignore();  
    getline(cin, title); 

    Book* book = lib.find(title);

    if( book != nullptr){
        cout << "Book found \n";
        // display book details

    }
    else{
        cout << "book not found \n";
    }
}

void BorrowBook(List lib){
    cout <<"Enter the title of the book that you want to borrow: ";
    string title;
    cin.ignore();  
    getline(cin, title); 

    Book*book = lib.find(title);

    if(book != nullptr){
        if(book->copies>0){
            book->copies--;
            cout <<"you have borrowed the boook: "<<book->title<<endl;
            cout << "Remaining copies: "<<book->copies<<endl;
        }
        else{
            cout <<"Sorry, no copies available to borrow.\n";
        }
    }
    else{
        cout << "book not found \n";
        }
}



int main() {
    // FindBook();
    return 0;
}
