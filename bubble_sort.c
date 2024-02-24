// C program to implement the Bubble sort algorithm.

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
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

Method: BubbleSort(A[], N)
    Repeat Step 1 for I = 0 to N - 1
        Repeat Step 2 for J = 1 to N - 1 - I
            If A[J - 1] > A[J]
                Swap A[J - 1] and A[J]
        [End of inner loop]
    [End of outer loop]
    Exit

*/
