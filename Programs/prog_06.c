#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = (n/2) - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void buildMaxHeap(int arr[], int n) {
    for (int i = (n/2) - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int arr[5];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the array[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int minHeap[5], maxHeap[5];
    for (int i = 0; i < n; i++) {
        minHeap[i] = arr[i];
        maxHeap[i] = arr[i];
    }
    buildMinHeap(minHeap, n);
    buildMaxHeap(maxHeap, n);
    printf("Min Heap:\n");
    printHeap(minHeap, n);
    printf("Max Heap:\n");
    printHeap(maxHeap, n);
    return 0;
}