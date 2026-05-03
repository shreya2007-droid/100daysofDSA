/*Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].*/
#include <stdio.h>

#define MAX 100

int temp[MAX];

// Merge function with inversion count
int merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // Count inversions
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge Sort with inversion count
int mergeSort(int arr[], int left, int right) {
    int mid, inv_count = 0;

    if (left < right) {
        mid = (left + right) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);

        inv_count += merge(arr, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n, arr[MAX];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = mergeSort(arr, 0, n - 1);

    printf("Number of inversions: %d\n", result);

    return 0;
}