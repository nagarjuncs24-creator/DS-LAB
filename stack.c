#include <stdio.h>
#define MAX 5   

int stack[MAX];
int top = -1;


void push() {
    int value;
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push element.\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Element %d pushed successfully.\n", value);
    }
}


void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No element to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


int main() {
    int choice;
    printf("---- Stack Implementation Using Array ----\n");

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
