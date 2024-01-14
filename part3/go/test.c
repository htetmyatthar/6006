#include <stdio.h>

// Function to find the maximum number in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(int arr[], int n, int exp, int base) {
    const int K = base;
    int output[n];
    int count[K];

    for (int i = 0; i < K; i++)
        count[i] = 0;

    // Count occurrences of digits at the current significant place
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % base]++;

    // Update count[i] to store the position of the next occurrence
    for (int i = 1; i < K; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(int arr[], int n, int base) {
    int max = getMax(arr, n);

    // Do counting sort for every digit place
    for (int exp = 1; max / exp > 0; exp *= base)
        countingSort(arr, n, exp, base);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Radix Sort with base 10
    radixSort(arr, n, 10);

    printf("\nSorted array in base 10: \n");
    printArray(arr, n);

    // Radix Sort with base 8 (octal)
    radixSort(arr, n, 8);

    printf("\nSorted array in base 8 (octal): \n");
    printArray(arr, n);

    return 0;
}
