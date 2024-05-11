#include <iostream>
#include <algorithm>

using namespace std;

int comparisons = 0;
int swaps = 0;

void shellSort(int arr[], int n)
{
    comparisons = 0;
    swaps = 0;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
                comparisons++;
                swaps++;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
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
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element number " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "The array before sorting by Shell Sort: " << endl;
    printArray(arr, size);

    shellSort(arr, size);
    cout << "The array after sorting by Shell Sort: " << endl;
    printArray(arr, size);

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;

    return 0;
}
