/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include <stdio.h>
#include <stdlib.h>

// Counting Sort (stable)
void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // Step 1: Find max element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Step 3: Store frequencies
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Prefix sums (cumulative count)
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build output array (RIGHT → LEFT for stability)
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        int val = arr[i];
        output[count[val] - 1] = val;
        count[val]--;
    }

    // Step 6: Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);
    printArray(arr, n);

    return 0;
}