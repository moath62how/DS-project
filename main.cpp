#include <iostream>
#include "List.h"  
using namespace std;

void FindBook(List lib) {
    string title;
    cout << "Enter the title of the book you search: ";
    cin >> title;

    Book* book = lib.find(title);

    if( book != nullptr){
        cout << "Book found \n";
        // display book details

    }
    else{
        cout << "book not found \n";
    }
}



int main() {
    // FindBook();
    return 0;
}
