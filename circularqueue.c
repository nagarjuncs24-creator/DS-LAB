#include <stdio.h>
#define SIZE 5

int cqueue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((rear + 1) % SIZE == front)
        printf("Queue Overflow! Circular queue is full.\n");
    else {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        cqueue[rear] = item;
        printf("%d inserted successfully.\n", item);
    }
}

void delete() {
    if (front == -1)
        printf("Queue Underflow! Circular queue is empty.\n");
    else {
        printf("Deleted element: %d\n", cqueue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        int i = front;
        printf("Circular Queue elements: ");
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
