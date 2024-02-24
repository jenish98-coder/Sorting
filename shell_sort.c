//a program to implement shell sort
#include <stdio.h>

void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i++) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            // shift earlier gap-sorted elements up until the correct location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

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

Method: ShellSort(A[], N)
    for GAP = N / 2; GAP > 0; GAP = GAP / 2
        for J = GAP to N - 1
            Set TEMP = A[J]
            for I = J; I >= GAP && A[I - GAP] > TEMP; I = I - GAP
                Set A[I] = A[I - GAP]
            Set A[I] = TEMP
    Exit

*/
