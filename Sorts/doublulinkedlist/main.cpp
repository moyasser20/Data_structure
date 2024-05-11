#include <iostream>

using namespace std;

class DoublyLinkedList{
    struct Node {
        int item;
        Node *next;
        Node *prev;
    };
    Node *first;
    Node *last;
    int count;

public:
    DoublyLinkedList()
    {
        first = last = NULL;
        count = 0;
    }
    bool isEmpty()
    {
        return (first == NULL);
    }
    void insertFirst(int element)
    {
        Node *newNode = new Node;
        newNode->item= element;

        if(count  == 0)
        {
            first = last = newNode;
            newNode->next=newNode->prev=NULL;
        }
        else
        {
            newNode->next = first;
            newNode->prev=NULL;
            first->prev = newNode;
            first=newNode;
        }
        count++;
    }
    void insertLast(int element) {
        Node *newNode = new Node;
        newNode->item = element;

        if (count == 0) {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        } else {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode; // Update last pointer
        }
        count++;
    }

    void insertAtPos(int pos, int element)
    {
        Node *newNode= new Node;
        newNode->item = element;

        if(pos<0 || pos > count)
        {
            cout<<"Out of Range"<<endl;
        }
        else if (pos == 0)
            insertFirst(element);
        else if(pos == count)
            insertLast(element);
        else
        {
            Node *cur = first;

            for(int i = 0 ; i < pos ; i++)
            {
                cur = cur->next;
            }
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next = newNode;
            cur->next->prev= newNode;
            count++; // Increment count after successful insertion
        }
    }
    void removeFirst(){
        if(count==0)
            cout<<"Empty List: ";
        else if(count == 1) {
            delete first;
            last=first=NULL;
        }
        else
        {
            Node *cur = first;
            first = first->next;
            first->prev=NULL;
            delete cur;
        }
        count -= 1;
    }
    void removeLast()
    {
        if (count == 0)
            cout<<"Empty List: ";
        else if(count  == 1) //first == last
        {
            delete first;
            last = first = NULL;
        }
        else
        {
            Node *cur = last;
            last = last->prev;
            last->next = NULL;
            delete cur;
        }
        count -= 1;
    }
    void remove(int element)
    {
        if(count == 0)
            cout<<"Empty list cant remove ";
        if(first->item == element) // Fix the comparison here
            removeFirst();
        else
        {
            Node *cur = first->next;
            while(cur != NULL)
            {
                if(cur->item == element) // Fix the comparison here
                    break;
                cur = cur->next;
            }
            if(cur == NULL)
                cout<<"The item is not there";
            else if(cur->next==NULL)
                removeLast();
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev=cur->prev;
                delete cur;
                count-=1;
            }
        }
    }

    void display()
    {
        cout<<"Element List..."<<endl;
        Node *cur = first;
        while(cur !=NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    void reverseDisplay()
    {
        cout<<"Element List after reverse:..."<<endl;
        Node *cur = last;
        while(cur !=NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->prev; // Traverse in reverse direction
        }
        cout<<endl;
    }
};

int main()
{
    DoublyLinkedList dl;
    dl.insertAtPos(0,10);
    dl.insertAtPos(1,20);
    dl.insertAtPos(2,30);
    dl.insertAtPos(3,40);
    dl.display();
    dl.removeFirst();
    dl.display();
    dl.reverseDisplay();
}
