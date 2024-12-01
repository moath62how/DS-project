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
    void add(Book data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            size++;
        }
        else
        {
            Node *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newNode;
            size++;
        }
    }
    void remove(string title)
    {
        Node *temp, *current = nullptr;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (head->data.title == title)
        {
            temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        else
        {
            temp = head;
            while (temp->next != NULL && temp->next->data.title != title)
            {
                current = temp;
                temp = temp->next;
            }
            current->next = temp->next;
            delete temp;
            size--;
            return;
        }
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
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
        cout << "LiST IS DELETED SUCCESSFUL" << endl;
    }
};
