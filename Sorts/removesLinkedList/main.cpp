#include <iostream>
using namespace std;

class LinkedList {
    struct Node {
        int item;
        Node *next;
    };
    Node *first;
    Node *last;
    int length;

public:
    LinkedList() {
        first = last = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void insertFirst(int element) {
        Node *newNode = new Node;
        newNode->item = element;
        if (length == 0) {
            first = last = newNode;
            newNode->next = NULL;
        } else {
            newNode->next = first;
            first = newNode;
        }
        length++;
    }

    void insertLast(int element) {
        Node *newNode = new Node;
        newNode->item = element;
        if (length == 0) {
            first = last = newNode;
            newNode->next = NULL;
        } else {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        length++;
    }

    void insertAtpos(int pos, int element) {
        if (pos < 0 || pos > length)
            cout << "Out Of Range";
        else {
            Node *newNode = new Node;
            newNode->item = element;
            if (pos == 0)
                insertFirst(element);
            else if (pos == length)
                insertLast(element);
            else {
                Node *Curr = first;
                for (int i = 1; i < pos; ++i) {
                    Curr = Curr->next;
                }
                newNode->next = Curr->next;
                Curr->next = newNode;
                length++;
            }
        }
    }

    void removeFirst() {
        if (length == 0)
            cout << "Empty List Cant remove " << endl;
        else {
            Node *curr = first;
            first = first->next;
            delete curr;
            length--;

            if (length == 0)
                last = NULL;
        }
    }

    void removelast() {
        if (length == 0) {
            cout << "Empty List Cant remove " << endl;
            return;
        } else if (length == 1) {
            delete first;
            last = first = NULL;
            length = 0;
        } else {
            Node *cur = first->next;
            Node *prev = first;
            while (cur->next != NULL) {
                prev = cur;
                cur = cur->next;
            }
            delete cur;
            prev->next = NULL;
            last = prev;
            length--;
        }
    }

    void removeAtpos(int element) {
        if (isEmpty()) {
            return;
        }
        Node *cur, *prev;
        if (first->item == element) {
            cur = first;
            first = first->next;
            delete cur;
            length = length - 1;
            if (length == 0)
                last == NULL;
        } else {
            cur = first->next;
            prev = first;
            while (cur != NULL) {
                if (cur->item == element)
                    break;
                prev = cur;
                cur = cur->next;
            }
            if (cur == 0)
                cout << "Not Found" << endl;
            else {
                prev->next = cur->next;
                if (last == cur)
                    last = prev;
                delete cur;
                length -= 1;
            }
        }
    }

    void reverse()
    {
        Node *prev, *next, *cur;
        prev = NULL;
        cur = first;
        next = cur->next;

        while (next != NULL) //curr!=NULL
        {
            next = cur->next;
            cur->next = prev;
            prev=cur;
            cur = next;
        }
        first=prev;
    }
    int search(int element)
    {
        Node *cur = first;
        int pos = 0;
        while(cur != NULL)
        {
            if(cur->item == element)
                return pos;
            cur = cur->next;
            pos+=1;
        }
        return -1;
    }


    void print() {
        Node *Cur = first;
        while (Cur != NULL) {
            cout << Cur->item << " ";
            Cur = Cur->next;
        }
    }
};

int main() {
    LinkedList l;
    l.insertFirst(10);
    l.insertLast(30);
    l.insertLast(40);
    l.insertAtpos(1, 20);
    l.insertFirst(0);
    l.insertLast(50);
    l.removeFirst();
    l.removelast();
    cout<<l.search(30);
    //l.reverse();
    //l.print();
    return 0;
}
