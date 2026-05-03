/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by start time)
int compare(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    return x[0] - y[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // Step 1: Sort intervals
    qsort(intervals, n, sizeof(intervals[0]), compare);

    // Step 2: Merge
    int merged[n][2];
    int k = 0;

    merged[k][0] = intervals[0][0];
    merged[k][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        // If overlapping
        if (intervals[i][0] <= merged[k][1]) {
            if (intervals[i][1] > merged[k][1]) {
                merged[k][1] = intervals[i][1];
            }
        }
        else {
            // No overlap → move to next interval
            k++;
            merged[k][0] = intervals[i][0];
            merged[k][1] = intervals[i][1];
        }
    }

    // Output
    for (int i = 0; i <= k; i++) {
        printf("%d %d\n", merged[i][0], merged[i][1]);
    }

    return 0;
}