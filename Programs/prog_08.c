#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 1000

void printList(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n, int *comp, int *swaps){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            (*comp)++;
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *comp, int *swaps){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            (*comp)++;
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*swaps)++;
        }
    }
}

void insertionSort(int arr[], int n, int *comp, int *swaps){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            (*comp)++;
            arr[j+1] = arr[j];
            j--;
            (*swaps)++;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int l, int m, int r, int *comp){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[3], R[5];
    for(int i = 0; i < n1; i++) L[i] = arr[l+i];
    for(int j = 0; j < n2; j++) R[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        (*comp)++;
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r, int *comp){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m, comp);
        mergeSort(arr, m+1, r, comp);
        merge(arr, l, m, r, comp);
    }
}

int main(){
    int N, choice;
    int comparisons = 0, swaps = 0;

    printf("Enter total number of integers: ");
    scanf("%d", &N);

    int arr[5];
    srand(time(NULL));

    for(int i = 0; i < N; i++)
        arr[i] = (rand() % (MAX - MIN + 1)) + MIN;

    printf("\nUnsorted List:\n");
    printList(arr, N);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            bubbleSort(arr, N, &comparisons, &swaps);
            break;
        case 2:
            selectionSort(arr, N, &comparisons, &swaps);
            break;
        case 3:
            insertionSort(arr, N, &comparisons, &swaps);
            break;
        case 4:
            mergeSort(arr, 0, N-1, &comparisons);
            swaps = 0; 
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nSorted List:\n");
    printList(arr, N);

    printf("\nTotal Comparisons: %d\n", comparisons);
    printf("Total Swaps: %d\n", swaps);

    return 0;
}