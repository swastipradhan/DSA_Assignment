#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;           
    struct Node* next;  
};

void reverseTraversal(struct Node* head) {
    
    if (head == NULL) {
        return;
    }
    
  
    reverseTraversal(head->next);
    
   
    printf("%d -> ", head->data);
}


struct Node* createNode(int data) {
  
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
   
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}


 
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
   
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
   
    temp->next = newNode;
}


void normalTraversal(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    struct Node* head = NULL;  

     

    
    
  
    printf("Step 1: Creating linked list.\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Linked list created successfully!\n\n");
    
    
    printf("Step 2: Normal Traversal (Forward):\n");
    normalTraversal(head);
    printf("\n");
    
   
    printf("Step 3: Reverse Traversal (Backward):\n");
    reverseTraversal(head);
    printf("NULL\n\n");
    
    
    printf("How Reverse Traversal Works:\n");
    
    printf("1. The function uses RECURSION\n");
    printf("2. It goes to the END of the list first\n");
    printf("3. Then prints while COMING BACK\n");
    printf("4. This naturally reverses the order!\n\n");
    
    printf("Recursion Flow:\n");
    printf("reverseTraversal(10) -> calls reverseTraversal(20)\n");
    printf("reverseTraversal(20) -> calls reverseTraversal(30)\n");
    printf("reverseTraversal(30) -> calls reverseTraversal(40)\n");
    printf("reverseTraversal(40) -> calls reverseTraversal(50)\n");
    printf("reverseTraversal(50) -> calls reverseTraversal(NULL)\n");
    printf("reverseTraversal(NULL) -> returns (base case)\n");
    printf("Now printing happens while returning:\n");
    printf("Print 50, Print 40, Print 30, Print 20, Print 10\n\n");
    
   
    freeList(head);
    
    printf("Memory freed successfully!\n");
   
    
    return 0;
}