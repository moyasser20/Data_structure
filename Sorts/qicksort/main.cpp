 #include <iostream>
#include <algorithm>

using namespace std;

int partition1(int arr[] , int l , int h)
{
    int  p = arr[l];
    int i = l;
    int j = h;
     while(i < j)
     {
         do
         {
             i++;
         }while(arr[i] <= p);
         do {
             j--;
         }while(arr[j] > p);

         if(i < j)
             swap(arr[i], arr[j]);
     }
    swap(arr[l] , arr[j]);
     return j;
}
void quicksort1(int arr[] , int l , int h)
{
    if(l < h)
    {
        int piv= partition1(arr,l,h);
        quicksort1(arr,l,piv);
        quicksort1(arr,piv+1 , h);
    }
}
//partion 2







void printarray(int arr[],int size)
{
    for(int i = 0 ; i <size ; i++)
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
    cout<<"Enter the element of the array: "<<endl;
    for(int i = 0; i < size ; i++)
    {
        cout<<"Enter the element number "<< i + 1<<" : ";
        cin>>arr[i];
    }
    cout<<"The array before sorting by quick sort: "<<endl;
    printarray(arr,size);
    cout<<"The array after sorting by quick sort: "<<endl;
    quicksort1(arr, 0 , size);
    printarray(arr,size);

}