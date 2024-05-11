#include <iostream>

using namespace std;

void insertsort(int arr[] , int n)
{
    int key, j;                 //0   1   2   3  4  5  6
    int swaps=0;
    int comparisons = 0;
    for(int i = 1; i < n ; i++)//60 90   80  30 50 70 40
    {
        key=arr[i];//90
        j = i - 1; //0 , (1,0), (2,1,0) ...

        while(j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key; //90
        swaps++;

    }
    cout<<"swaps is: "<<swaps<<endl;
    cout<<"Comparisons is: "<<comparisons<<endl;
}
void printarr(int arr[] , int size)
{
    for(int i = 0 ; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size]; // Declare the array after obtaining the size

    cout << "Enter the elements of the array: " << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << "Enter element number " << i+1 << " : ";
        cin >> arr[i];
    }

    cout << "The array before insertion Sort: " << endl;
    printarr(arr, size);

    cout << "The array after insertion Sort: " << endl;
    insertsort(arr, size);
    printarr(arr, size);

    return 0;
}
