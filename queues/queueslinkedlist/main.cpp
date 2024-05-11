#include <iostream>
using namespace std;

class linkedQueue{

    struct Node{
        Node *next;
        int item;
    };
    Node *front;
    Node *rear;
    int length;

public:
    linkedQueue()
    {
        front = rear = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return length = 0;
    }
    void Enqueue(int element)
    {
        if(isEmpty())
        {
            front =new Node;
            front->item = element;
            front->next = NULL;
            rear = front;
            length++;
        }
        else
        {
            Node *newNode = new Node;
            newNode->item = element;
            newNode->next = NULL;
            rear->next = newNode;
            rear = newNode;
            length++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
            cout<<"Empty queue";
        else
        {
            Node *temp = front;
            if(front = rear)
            {
                front = NULL;
                rear = NULL;
            } else
                front = front->next;
            temp->next = NULL;

            delete temp;

        }
    }
};