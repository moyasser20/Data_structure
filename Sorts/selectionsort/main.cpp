#include <iostream>
// #include <algorithm> // Not needed anymore
using namespace std;

void selectionSort(int arr[], int n)
{
    int minIndx;
    int comparisons;
    int swaps;

    for(int i = 0 ; i < n-1; i++)//0  1  2  3  4  5
    {                           //60 40 50  40 10 20
        minIndx = i; // 60 ,40,....

        for(int j = i + 1; j < n ; j++) {
            comparisons++;
            if (arr[j] < arr[minIndx]) {
                minIndx = j;
            }
        }

        // Swap elements directly
        int temp = arr[minIndx];
        arr[minIndx] = arr[i];
        arr[i] = temp;
        swaps++;
    }
    cout<<"comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;
}

void printarray(int arr[], int size)
{
    for(int i = 0 ; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of the array" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << "Enter element Number " << i+1 << " : ";
        cin >> arr[i];
    }
    cout << "The array before sorting By Selection Sort" << endl;
    printarray(arr, size);

    cout << "The array after sorting By selection Sort" << endl;
    selectionSort(arr, size);
    printarray(arr, size);

    return 0;
}
