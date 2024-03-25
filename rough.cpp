#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // Call max heapify on the reduced heap
    }
}

int main() {
    int arr[] = {10, 5, 20, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    display(arr, n);

    heap_sort(arr, n);

    cout << "Array after sorting: ";
    display(arr, n);

    return 0;
}
