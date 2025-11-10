#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createlist(int n){
    int data;
    struct Node *temp, *newNode;
    if(n<=0){
        printf("Number of node should be greater than 0.\n");
        return ;
    }
    printf("Enter data for node 1: ");
    scanf("%d",&data);
    head = createNode(data);
    temp = head;

    for(int i=2;i<=n;i++){
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        newNode = createNode(data);
        temp->next = newNode;
        temp = newNode;
    }
    printf("Linked list created successfully.\n");
}

void displaylist(){
    struct Node *temp = head;
    if(head == NULL){
        printf("List is empty.\n");
        return ;
    }
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL.\n");
}

void insertAtBeginning(int data){
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

void insertAtEnd(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return ;
    }
    struct Node *temp = head;
    while(temp->next != NULL)
            temp = temp->next;
    temp->next = newNode;
    printf("Node inserted at the end.\n");
}

void insertAtPosition(int data,int pos){
    struct Node *newNode = createNode(data);
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position 1.\n");
        return ;
    }
    struct Node *temp = head;
    for(int i = 1;i <pos-1 & temp != NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of the range.\n");
        free(newNode);
    }else{
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", pos);
    }
}

int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Any Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createlist(n);
            break;
        case 2:
            displaylist();
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 5:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertAtPosition(data, pos);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
