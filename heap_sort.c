// a program to implement the Heap sort algorithm

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

/*
Algorithm used:
Input: Array A of elements to be sorted and its size N
Output: Sorted array A

Method: HeapSort(A[], N)
    BuildMaxHeap(A, N)
    for I = N to 2
        Swap A[1] with A[I]
        MaxHeapify(A, 1, I - 1)
    Exit

Method: BuildMaxHeap(A[], N)
    for I = N / 2 downto 1
        MaxHeapify(A, I, N)
    Exit

Method: MaxHeapify(A[], I, N)
    Set Left = 2 * I
    Set Right = 2 * I + 1
    Set Largest = I
    If Left <= N and A[Left] > A[Largest]
        Set Largest = Left
    If Right <= N and A[Right] > A[Largest]
        Set Largest = Right
    If Largest != I
        Swap A[I] with A[Largest]
        MaxHeapify(A, Largest, N)
    Exit

*/