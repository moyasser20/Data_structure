#include <iostream>
using namespace std;

void maxheapify(int arr[], int i, int size)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheapify(arr, largest, size);
    }
}

void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, i, n);
}

void heapsort(int arr[] ,int n)
{
    buildheap(arr,n);
    for(int i = n-1 ; i>=0 ; i--)
    {
        swap(arr[0] ,arr[i]);
        maxheapify(arr,0,i);
    }
}

void print(int arr[] , int n)
{
    cout<<"Sorted elements in max heap order: "<<endl;
    for(int i = 0; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}


int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the Elements Of The Array "<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<"Enter Element Number "<<i+1<<" : ";
        cin>>arr[i];
    }

    heapsort(arr,size);
    print(arr,size);

    return 0;
}