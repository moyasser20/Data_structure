#include <iostream>
using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

bool heap_increase_key(int arr[], int i, int key) {
    if (key < arr[i]) {
        cout << "Error: New Key is Smaller than current Key" << endl;
        return false;
    }

    arr[i] = key;
    while (i > 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
    return true;
}

void max_heap_insert(int arr[], int& n, int key) {
    n++;
    arr[n - 1] = INT_MIN; // -∞
    heap_increase_key(arr, n - 1, key);
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the initial size of the array: ";
    cin >> size;

    int arr[size + 1]; // Adding one extra element for the new insertion
    cout << "Enter the initial elements of the array" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Enter element number " << i + 1 << " : ";
        cin >> arr[i];
    }

    int n = size; // Current heap size
    cout << "Enter the key to insert: ";
    int key;
    cin >> key;

    cout << "Array before insertion: ";
    print_array(arr, n);

    max_heap_insert(arr, n, key);

    cout << "Array after insertion: ";
    print_array(arr, n);

    return 0;
}
