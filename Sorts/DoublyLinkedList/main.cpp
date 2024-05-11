#include <iostream>

using namespace std;

class doublyLinkedList{

    struct Node{
        int item;
        Node *next;
        Node *prev;
    };
    Node *first;
    Node *last;
    int count;

public:
    doublyLinkedList()
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    bool isEmpty()
    {
        return (first == NULL);
    }
    void insertFirst(int element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        if(count == 0)
        {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;
        }
        count++;
    }
    void insertlast(int element)
    {
        Node *newNode = new Node;
        newNode->item = element;

        if(count == 0) {
            first = last = NULL;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
        }
        count++;
    }

    void insertarpos(int pos,int element)
    {
        Node *newNode = new Node;
        if(pos < 0 || pos > count)
        {
            cout<<"Out Of Range: ";
        }
        else
        {
            Node *cur = first;
            for(int i = 1 ; i < pos ; i++)
            {
                cur = cur->next;
            }
            newNode->next = cur->next;
            newNode->prev = cur->next;
            newNode->prev = cur;
            cur->next = newNode;
            cur->next->prev=newNode;

        }
    }
};