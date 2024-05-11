#include <iostream>
using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

void max_heapify(int arr[], int i, int size) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size);
    }
}

bool heap_increase_key(int arr[], int i, int key) {
    if (key < arr[i]) {
        cout << "Error: new key is smaller than current key" << endl;
        return false;
    }

    arr[i] = key;
    while (i > 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
    return true;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Enter element number " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "Enter the index i and the new key: ";
    int i, key;
    cin >> i >> key;

    cout << "Array before increasing key: ";
    print_array(arr, size);

    if (heap_increase_key(arr, i, key)) {
        cout << "Array after increasing key: ";
        print_array(arr, size);
    }

    return 0;
}
