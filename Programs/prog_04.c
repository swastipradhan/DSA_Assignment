#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* head = NULL;

void displayList(){
    Node* current = head;
    if(current == NULL){
        printf("Empty list \n");
        return;
    }
    printf("[ ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf(" ]\n");
}

void insertEnd(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insertAfterNode(Node* pre, int value){
    if(pre == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = pre;
    newNode->next = pre->next;

    if(pre->next != NULL){
        pre->next->prev = newNode;
    }

    pre->next = newNode;
} 

void deleteNodeByValue(int value){
    if(head == NULL) return;

    if(head->next == NULL && head->data == value){
        free(head);
        head = NULL;
        return;
    }
    Node* current = head;
    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }
    if(current->next == NULL){
        printf("No data \n");
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    if(temp->next != NULL){
        temp->next->prev = current;
    }
    free(temp);
}

int main(){
    insertEnd(10);
    insertEnd(15);
    insertAfterNode(head,20);
    insertAfterNode(head->next, 30);
    displayList();
    deleteNodeByValue(30);
    displayList();
    return 0;
}