4. How can we implement the doubly linked list using structure? Write a method to insert(after given node) and delete the node in doubly linked list. Write main() to demonstrate the use of the functions.
->A doubly linked list is a list where each node stores data, has pointer to the previous node and has pointer to the next node.

This program implements a doubly linked list in C using structures. Each node contains: data: which is a integer value next: which is pointer to the next node prev: pointer to the previous node

The function used in this list is:

displayList() This displays all element of the list from head to the end and prints "Empty list" if the list has node.

insertEnd(iny value) It inserts a new node at the end of the list and handles the case when the list is empty.

insertAfterNode(Node* pre,int value) It inserts a new node after a given node(pre) and updates both next and prev pointers correctly.

deleteNodeByValue(int value) It deletes the first node that contains the given value. It handles the following list: Empty list Single-node list Value not sound in the list.