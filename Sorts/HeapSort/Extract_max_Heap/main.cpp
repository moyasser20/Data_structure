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

int heap_extract_max(int arr[], int& n)
{
    if (n < 1)
    {
        cout << "Error: heap underflow" << endl;
        exit(1);
    }

    int max = arr[0];
    arr[0] = arr[n - 1];
    n--;
    maxheapify(arr, 0, n);
    return max;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element number " << i + 1 << " : ";
        cin >> arr[i];
    }

    int max;
    if (size >= 1)
    {
        max = heap_extract_max(arr, size);
        cout << "Max element extracted: " << max << endl;
        cout << "Updated array after extraction: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Error: heap underflow" << endl;
    }

    delete[] arr;

    return 0;
}