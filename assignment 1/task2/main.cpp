#include <iostream>
using namespace std;

int comparisons = 0;
int swapss = 0;

//Selection Sort
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int n)
{
    comparisons = 0; // Reset comparisons
    swapss = 0;      // Reset swaps

    int minIndex;
    for (int i = 0; i < n - 1; i++) //0   1   2   3   4   5
    {                               //60  40  50  30  10  20
        minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            swapss++;
        }
    }
    cout << "The number of comparisons is : " << comparisons << endl;
    cout << "The number of swaps is: " << swapss << endl;
}

//Merge Sort
void merge(int arr[], int l, int m, int r) // m =l + (r-l) / 2  "0 , 6"
{
    int i, j, k;
    int n1 = m - l + 1; // first subarray is arr[1..m]    "3-0+1 = 4"
    int n2 = r - m;     // second subarray is arr[m+1..r]     "6 - 3 = 3"
    int *L = new int[n1], *R = new int[n2];                    // dynamic array to pass the size

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l; //0

    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) // 60 10 20 5 60 70
{
    if (l < r)
    {
        int m = l + (r - l) / 2; //3

        mergeSort(arr, l, m);     //for left array;
        mergeSort(arr, m + 1, r); //for right array;

        merge(arr, l, m, r);
    }
}


// Shell Sort
void shellSort(int arr[], int n)
{
    comparisons = 0;
    swapss = 0;

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
                swapss++;
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
    int choice;
    cout << "=====================================" << endl;
    cout << "=================Menu================" << endl;
    cout << "=====================================" << endl;
    cout << "1-Selection Sort" << endl;
    cout << "2-Merge Sort" << endl;
    cout << "3-shell sort" << endl;
    cout << "4-Exit"<<endl;
    cout << "Enter the choice You Want to Test: " << endl;
    cin >> choice;

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element number " << i + 1 << " : ";
        cin >> arr[i];
    }

    switch (choice)
    {
        case 1:
            cout << "The array before sorting By Selection Sort: ";
            printArray(arr, size);
            selectionSort(arr, size);
            cout << "The array after Sorting by Selection Sort: ";
            printArray(arr, size);
            break;
        case 2:
            cout << "The array before Sorting By Merge Sort: ";
            printArray(arr, size);
            mergeSort(arr, 0, size - 1);
            cout << "The array after Sorting By Merge Sort: ";
            printArray(arr, size);
            cout << "The Number of comparisons is: " << comparisons << endl;
            cout << "The Number of swaps is: " << swapss << endl;
            break;
        case 3:
            cout << "The array before sorting by Shell Sort: " << endl;
            printArray(arr, size);

            shellSort(arr, size);
            cout << "The array after sorting by Shell Sort: " << endl;
            printArray(arr, size);

            cout << "Number of comparisons: " << comparisons << endl;
            cout << "Number of swaps: " << swapss << endl;
            break;
        case 4:
            cout<<"ThankYou for Using My programme!";
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
