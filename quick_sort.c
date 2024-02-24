//a program to implement the Quick sort algorithm

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

/*
Algorithm used:
Input: Array A of elements to be sorted, start index I, end index J
Output: Sorted array A

Method: QuickSort(A[], I, J)
    Set L = I, R = J
    If I < J
        Set P = Partition(A, I, J)
        QuickSort(A, I, P - 1)
        QuickSort(A, P + 1, J)
    Exit

Method: Partition(A[], I, J)
    Set Pivot = A[I]
    While L < R
        while L < R && A[L] <= Pivot
            L = L + 1
        while A[R] > Pivot
            R = R - 1
        If L < R
            Swap A[L] with A[R]
    Swap A[I] with A[R]
    Return R

*/