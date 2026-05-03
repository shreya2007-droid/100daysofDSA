/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>

// Sort two arrays by the "start" array
void sort(int start[], int end[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (start[j] > start[j + 1]) {
                int temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;

                temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;
            }
        }
    }
}

int min_meeting_rooms(int start[], int end[], int n) {
    if (n == 0) return 0;

    sort(start, end, n);

    int room = 0, res = 0;
    int i = 0, j = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            room++;
            i++;
        } else {
            room--;
            j++;
        }
        if (room > res) res = room;
    }

    return res;
}

int main() {
    int start[] = {2, 9, 6};
    int end[]   = {4, 12, 10};
    int n = 3;

    printf("Minimum rooms required: %d\n", min_meeting_rooms(start, end, n));
    return 0;
}
