#include <iostream>
#include <assert.h>

using namespace std;
const int MAX_LENGTH = 100;

template <class t>
class arrayQueueType
{
    int rear;
    int front;
    int length;
    t *arr;

public:
    arrayQueueType(int size)
    {
        if(size <= 0)
            size = 6;

        front  = 0;
        arr = new t[size];
        rear = MAX_LENGTH - 1;
        length = 0;
    }
    bool isEmpty(){
        return length == 0;
    }
    bool isFull(){
        return length == MAX_LENGTH;
    }

    void addQueue(t element)
    {
        if(isFull())
            cout<<"Queue is full and cannot to enqueue.."<<endl;

        else
        {
            rear = (rear + 1) % MAX_LENGTH;
            arr[rear] = element;
            length++;
        }
    }
    void deleteQueue()
    {
        if (isEmpty())
            cout<<"Queue is Empty cannot dequeue.."<<endl;

        else
        {
            front = (front + 1) % MAX_LENGTH;
            length--;
        }
    }

    int frontqueue()
    {
        assert(!isEmpty());
        return  arr[front];
    }
    int rearqueue()
    {
        assert(!isEmpty());
        return  arr[rear];
    }

    int queueSearch(t element)
    {
        int pos = -1;
        if (!isEmpty())
        {
            for (int i = front; i != rear; i = (i + 1) % MAX_LENGTH)
            {
                if (arr[i] == element)
                {
                    pos = i;
                    break;
                }
            }
            if (pos == -1)
            {
                if (arr[rear] == element)
                    pos = rear;
            }
        }
        else
            cout << "Queue is empty" << endl;

        return pos;
    }




    //circular
    void print()
    {
        if(!isEmpty())
        {
            for(int i = front ; i < rear +1 ; i = (i+1) % MAX_LENGTH)
            {
                cout<<arr[i]<<" ";
            }
        }
        else
        {
            cout<<"Empty Queue"<<endl;
        }

    }

};

int main()
{
    int size;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    arrayQueueType<int> q1(size);

    cout<<"Enter the elements of the queue "<<endl;
    for(int i = 0 ; i < size ; i++)
    {
        int element;
        cout<<"Enter element number  "<<i+1<<" : ";
        cin>>element;
        q1.addQueue(element);
    }

    q1.print();
    cout<<endl;
    cout<<"Front of the queue: "<<q1.frontqueue()<<endl;
    cout<<"Rear of the queue: "<<q1.rearqueue()<<endl;

    int searchelement;
    cout<<"Enter the element to search: ";
    cin>>searchelement;

    int pos = q1.queueSearch(searchelement);
    if(pos!=-1)
    {
        cout<<"Element found at position: "<<pos<<endl;
    }
    else
    {
        cout<<"Element not found in the queue. "<<endl;
    }

    return 0;
}