3. Write and Implement the reverse traversal algorithm in the the linked list. Write main() to demonstrate the use of the function.

This C program demonstrates how to traverse a linked list in reverse order using recursion. It creates a simple linked list and displays it both forward and backward.

What This Program Does?

Creates a linked list with 5 nodes (10, 20, 30, 40, 50) Displays the list in normal order (forward) Displays the list in reverse order (backward) Explains how the reverse traversal works Frees all allocated memory

Key Concepts to Understand:

Recursion
A function that calls itself Needs a base case to stop (NULL in our case) Uses the call stack to remember where to return

Linked List
Dynamic data structure Each node points to the next node Last node points to NULL

Memory Management
malloc() allocates memory for new nodes free() releases memory when done Always free memory to prevent leaks.