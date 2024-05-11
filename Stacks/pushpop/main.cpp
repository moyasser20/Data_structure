#include <iostream>

using namespace std;
const int max_size = 100;
template <class t>
class stack
{
    int top;
    t item[max_size];

public:
    stack(): top(-1){}

    void push(t element)
    {
        if(top >= max_size) // 0 --> 99
            cout<<"stack is full to push"<<endl;
        else {
            top++;
            item[top] = element;
        }
    }
    bool isEmpty()
    {
        return top < 0;
    }
    void pop()
    {
        if(isEmpty())
            cout<<"stack is empty to pop"<<endl;

        else
            top--;
    }
    void pop(t &element) // ahfz kemet el pop dakhl el motghyer
    {
        if(isEmpty())
            cout<<"Stack is empty to pop"<<endl;
        else
        {
            element = item[top];
            top--;
        }
    }
    void getop(t &stacktop)
    {
        if(isEmpty())
            cout<<"Stack is empty to pop"<<endl;
        else
        {
            stacktop = item[top];
            cout<<stacktop<<endl;
        }
    }
    void print()
    {
        cout<<"[ ";
        for (int  i = 0 ; i <= top ; i++) {
            cout << item[i];
            if(i < top)
                cout<<" , ";
        }
        cout<<" ]";
        cout<<endl;
    }
};

int main()
{
    stack <int> s1;
    s1.push(68);
    s1.push(200);
    s1.push(131);
    s1.push(245);
    s1.push(3415);
    s1.pop();
    s1.push(7);
    s1.print();

}