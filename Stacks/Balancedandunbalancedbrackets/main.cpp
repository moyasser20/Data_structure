#include <iostream>
#include <stack>
using namespace std;

bool arePair(char open, char close)
{
    if(open == '(' && close == ')')
        return true;
    else if(open =='{' && close == '}')
        return false;
    else if(open =='[' && close == ']')
        return true;
    return false;
}
bool areBalanced(string exp)
{
    stack <char> s;
    for(int i = 0 ; i < exp.length() ; i++)
    {
        if(exp[i] =='(' || exp[i] =='{' || exp[i] == '[')
            s.push(exp[i]);
        else if(exp[i] ==')' || exp[i] =='}' || exp[i] == ']')
        {
            if(s.empty() || !arePair(s.top(),exp[i]))
            {
                return false;
            }
            s.pop(); // Move the s.pop() here
        }
    }
    return s.empty()? true:false;
}

int main()
{
    string exp;
    cout<<"Enter an experssion "<<endl;
    cin>>exp;
    if(areBalanced(exp))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;
}