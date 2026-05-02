/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float val;
    struct Node* next;
};

// Insert in sorted order (Insertion Sort in bucket)
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    // Insert at beginning
    if (*head == NULL || (*head)->val >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse and insert
    struct Node* curr = *head;
    while (curr->next != NULL && curr->next->val < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; // [0,1) → bucket index
        insertSorted(&buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->val;
            curr = curr->next;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

// Print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}