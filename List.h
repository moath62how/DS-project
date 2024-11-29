#include <iostream>
using namespace std;
#include "Node.h"
template <typename T>

class List
{
    Node<T> *head;
    unsigned int size;

public:
    List()
    {
        size = 0;
        head = NULL;
    }

    ~List()
    {
        Node *temp1 = head;
        Node *temp2 = NULL;

        while (temp1 != NULL)
        {
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }
};
