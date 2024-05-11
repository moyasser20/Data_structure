#include <iostream>
using namespace std;

class LinkedList{
    struct Node
    {
        int item;
        Node *next;
    };
    Node *first;
    Node *last;
    int length;

public:
    LinkedList()
    {
        first = last = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return  length == 0;
    }
    void insertFirst(int element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        if(length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = first;
            first = newNode;
        }
        length++;
    }
    void insertLast(int element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        if(length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else
        {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        length++;
    }


    void insertAtpos(int pos, int element)
    {
        if(pos<0 || pos>length)
            cout<<"Out Of Range";
        else{
            Node *newNode = new Node;
            newNode->item = element;
            if(pos == 0)
                insertFirst(element);
            else if (pos == length)
                insertLast(element);
            else
            {
                Node *Curr = first;
                for (int i = 1; i < pos; ++i)
                {
                    Curr = Curr->next;
                }
                newNode->next = Curr->next;
                Curr->next = newNode;
                length++;
            }
        }
    }
    void print()
    {
        Node *Cur = first;
        while (Cur !=NULL)
        {
            cout<<Cur->item<<" ";
            Cur = Cur->next;
        }
    }
};

int main()
{
    LinkedList l;
    l.insertFirst(10);
    l.insertLast(30);
    l.insertLast(40);
    l.insertAtpos(1,20);
    l.print();
    return 0;
}