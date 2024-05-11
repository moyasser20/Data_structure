#include <iostream>
using namespace std;

template <class T>
class stack {
private:
    struct node {
        T item;
        node* next;
    };
    node* top;
    node* cur;

public:
    stack() {
        top = NULL;
    }

    void push(T newItem) {
        node* newitemptr = new node;
        if (newitemptr == NULL) {
            cout << "Stack push cannot allocate memory";
        }
        else {
            newitemptr->item = newItem;
            newitemptr->next = top;
            top = newitemptr;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void pop() {
        if (isEmpty())
            cout << "Stack empty on pop";
        else {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void pop(T& stacktop) {
        if (isEmpty())
            cout << "Stack empty on pop";
        else {
            stacktop = top->item;
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void gettop(T& stacktop) {
        if (isEmpty())
            cout << "Stack empty on pop";
        else
            stacktop = top->item;
    }

    void display() {
        cur = top;
        cout << "\nItems in the stack: ";
        cout << "[ ";
        while (cur != NULL) {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]";
    }
};

int main() {
    stack<int> s;
    s.push(123);
    s.push(456);
    s.push(789);
    s.push(101112);
    s.display();
    return 0;
}
