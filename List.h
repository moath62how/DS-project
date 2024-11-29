#include <iostream>
using namespace std;
#include "Node.h"

class List
{
    Node *head;
    unsigned int size;

public:
    List()
    {
        size = 0;
        head = NULL;
    }

    Book *find(string title)
    {
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            if (temp->data.title == title)
            {
                return &temp->data;
            }
        }
        return nullptr;
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
