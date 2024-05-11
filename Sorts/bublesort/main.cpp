#include <iostream>
#include <algorithm>
using namespace std;
void bublesort(int arr[], int n)
{
    bool flag = true;
    int c = 0; // Count for the number of rounds
    int swaps = 0; // Count for the number of swaps
    int comparisons = 0; // Count for the number of comparisons

    for (int i = 0; i < n - 1; i++) // 100 60 20 50 30 90
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
                swaps++; // Increment swaps when a swap occurs
            }
            comparisons++; // Increment comparisons for each comparison
        }
        c++; // Increment the round count
        if (flag == true)
            break;
    }
    cout << "Number of rounds: " << c << endl;
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;
}


void printarray(int arr[] , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];

    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0 ; i < size; i++)
    {
        cout<<"Enter element number "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"The array Before Bubble Sort: "<<endl;
    printarray(arr,size);
    cout<<"The array after Bubbl Sort: "<<endl;
    bublesort(arr,size);
    printarray(arr,size);
}