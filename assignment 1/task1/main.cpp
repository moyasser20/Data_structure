#include <iostream>
using namespace std;

void insertionSortLinear(int arr[], int size)
{
    int shifts = 0;
    int comparisons = 0;
    for (int i  = 1; i < size;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            ++comparisons;
            arr[j + 1] = arr[j];
            --j;
            ++shifts;
        }
        ++comparisons;
        arr[j + 1] = key;

    }
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;
}

void insertionSortBinary(int arr[], int n)
{
    int comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int low = 0;
        int high = i - 1;
        int j;


        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            comparisons++;
        }


        for (j = i - 1; j >= low; --j) {
            arr[j + 1] = arr[j];
            shifts++;
        }

        arr[j + 1] = key;
    }

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;
}


void PrintArray(int arr[],int size){
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int choice1;




    cout<<"Choose between insertion by linear Or Binary: \n";
    cout<<"1.Linear\n";
    cout<<"2.Binary\n";
    cout<<"3.Exit First task\n";
    cin >> choice1;


    do{

        cout<<"Choose between insertion by linear Or Binary: \n";
        cout<<"1.Linear\n";
        cout<<"2.Binary\n";
        cout<<"3.Exit First task\n";
        cin >> choice1;

        switch (choice1) {
            case 1: {

                int size2;
                cout << "Enter Size of the array to be sorted in Linear search: \n";
                cin >>size2;
                int arr2[size2];

                for (int i = 0;i<size2;i++) {
                    cout<<"Enter element in index "<<i+1 <<" :";
                    cin >>arr2[i];
                }

                cout<<"Array Unsorted: \n";
                PrintArray(arr2,size2);
                insertionSortLinear( arr2, size2);
                cout << "Array Sorted with Linear search: \n";
                PrintArray(arr2,size2);
                break;
            }

            case 2: {

                int size;
                cout << "Enter Size of the array to be sorted in Binary search: \n";
                cin >>size;
                int arr[size];

                for (int i = 0;i<size;i++) {
                    cout<<"Enter element in index "<<i+1 <<" :";
                    cin >>arr[i];
                }

                cout<<"Array Unsorted: \n";

                PrintArray(arr,size);
                insertionSortBinary(arr, size);
                cout << "Array Sorted with Binary search: \n";
                PrintArray(arr,size);
                break;
            }

        }

    }while(choice1 != 3);

    return 0;
}