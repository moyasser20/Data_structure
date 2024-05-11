#include <iostream>
using namespace std;
void merge(int arr[], int l , int m , int r) // m =l + (r-l) / 2  "0 , 6"
{
    int i , j , k;
    int n1 = m - l + 1; // first subarray is arr[1..m]    "3-0+1 = 4"
    int n2 = r - m; // second subarray is arr[m+1..r]     "6 - 3 = 3"
    int *L = new int[n1], *R=new int[n2];  // dynamic array to pass the size


    for(i = 0  ; i < n1 ; i++)
        L[i] = arr[l + i];

    for(j= 0  ; j < n2 ; j++)
        R[j] = arr[m + 1 + j];


    i = j = 0;
    k = l; //0

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j])
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


void mergesort(int arr[] , int l , int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; //3

        mergesort(arr,l,m); //for left array;
        mergesort(arr,m + 1, r); //for right array;

        merge(arr,l,m,r);
    }
}

void printarray(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
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

    cout<<"Enter the elements of the array: "<<endl; // 60 10 20 5 60 70
    for(int i = 0; i < size ; i++)
    {
        cout<<"Enter element number  "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"The element before sorting by merge is "<<endl;
    printarray(arr,size);
    cout<<"The element after sorting by merge is "<<endl;
    mergesort(arr,0 , size-1);
    printarray(arr,size);
}