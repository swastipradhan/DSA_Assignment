#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Function to push element onto stack
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
    printf("  Pushed '%c' onto stack\n", c);
}

// Function to pop element from stack
char pop() {
    if (top < 0) {
        printf("  Stack Underflow\n");
        return '\0';
    }
    char c = stack[top--];
    printf("  Popped '%c' from stack\n", c);
    return c;
}

// Function to check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to get top element without removing it
char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

// Function to check if character is opening bracket
bool isOpening(char c) {
    return (c == '(' || c == '[' || c == '{');
}

// Function to check if character is closing bracket
bool isClosing(char c) {
    return (c == ')' || c == ']' || c == '}');
}

// Function to check if brackets match
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

// Main function to check if parentheses are balanced
bool isBalanced(char *expression) {
    top = -1; // Reset stack
    int len = strlen(expression);
    
    printf("\nChecking: %s\n", expression);
    
    for (int i = 0; i < len; i++) {
        char current = expression[i];
        
        // If opening bracket, push to stack
        if (isOpening(current)) {
            push(current);
        }
        // If closing bracket, check with stack top
        else if (isClosing(current)) {
            printf("  Found closing '%c'\n", current);
            
            if (isEmpty()) {
                printf("  ERROR: Stack is empty! No matching opening bracket.\n");
                return false;
            }
            
            char topChar = peek();
            if (isMatchingPair(topChar, current)) {
                printf("  Matches with '%c'\n", topChar);
                pop();
            } else {
                printf("  ERROR: '%c' does not match '%c'\n", topChar, current);
                return false;
            }
        }
    }
    
    // Check if stack is empty at the end
    if (isEmpty()) {
        printf("  Stack is empty at the end\n");
        printf("Result: BALANCED \n");
        return true;
    } else {
        printf("  Stack still has: ");
        for (int i = 0; i <= top; i++) {
            printf("'%c' ", stack[i]);
        }
        printf("\n");
        printf("Result: UNBALANCED  (Unclosed brackets)\n");
        return false;
    }
}

int main() {
   
    printf("  PARENTHESES BALANCE CHECKER\n");
    
    // Test Case 1
    char expr1[] = "a + (b - c) * (d";
    isBalanced(expr1);
    
    printf("\n");
    
    // Test Case 2
    char expr2[] = "m + [a - b * (c + d * {m)]";
    isBalanced(expr2);
    
    printf("\n");
    
    // Test Case 3
    char expr3[] = "a + (b - c)";
    isBalanced(expr3);
    
    printf("\n");
    
    // Additional test cases
    printf("\nADDITIONAL TESTS \n\n");
    
    char expr4[] = "{[()]}";
    isBalanced(expr4);
    
    printf("\n");
    
    char expr5[] = "((a + b) * [c - d])";
    isBalanced(expr5);
    
    return 0;
}