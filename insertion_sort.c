//a program to implement the Insertion sort algorithm.

#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

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

Method: InsertionSort(A[], N)
    Repeat Steps 2 to 5 for K = 1 to N - 1
        Set TEMP = A[K]
        Set J = K - 1
        Repeat while (TEMP <= A[J] && J >= 0)
            Set A[J + 1] = A[J]
            Set J = J - 1
        [End of inner loop]
        Set A[J + 1] = TEMP
    [End of loop]
    Exit

*/
