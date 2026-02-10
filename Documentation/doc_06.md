6. Given the array of the data (unsorted), Write a program to build the min and max heap.
-> This program demostrates the construction of Min Heap and Max Heap from a user provided array elements, builds both types of heaps, and prints them. It reads the array elements, builds both types of heaps, and prints them.

The key functions used in this program are:

swap(int *a, int *b)
minHeapify(int arr[], int n, int i)
maxHeapify(int arr[], int n)
buildMinHeap(int arr[],int n)
printHeap(int arr[],int n)
Program flow: Promots the user to input the number of elements. Reads the array elements from the user. Copies the input array into two separate arrays for Min Heap and Max Heap. Constructs min heap and max heap using respective functions. Prints the resulting heaps.