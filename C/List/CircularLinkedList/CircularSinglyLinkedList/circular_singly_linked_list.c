#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}


void insertAtBegin(struct Node** start, int item) {
    struct Node* newNode = createNode(item);
    if (*start == NULL) {
        newNode->next = newNode;
        *start = newNode;
    } else {
        struct Node* last = *start;
        while (last->next != *start)
            last = last->next;
        newNode->next = *start;
        *start = newNode;
        last->next = *start;
    }
}


void insertAtEnd(struct Node** start, int item) {
    struct Node* newNode = createNode(item);
    if (*start == NULL) {
        newNode->next = newNode;
        *start = newNode;
    } else {
        struct Node* last = *start;
        while (last->next != *start)
            last = last->next;
        last->next = newNode;
        newNode->next = *start;
    }
}


int deleteFromBegin(struct Node** start) {
    if (*start == NULL) {
        printf("Circular Singly Linked List is Empty.\n");
        return -1;
    }
    struct Node* temp = *start;
    struct Node* last = *start;
    while (last->next != *start)
        last = last->next;
    *start = (*start)->next;
    int deletedValue = temp->data;
    last->next = *start;
    free(temp);
    return deletedValue;
}


int deleteFromEnd(struct Node** start) {
    if (*start == NULL) {
        printf("Circular Singly Linked List is Empty.\n");
        return -1;
    }
    struct Node* temp = *start;
    struct Node* prev = NULL;
    while (temp->next != *start) {
        prev = temp;
        temp = temp->next;
    }
    int deletedValue = temp->data;
    prev->next = *start;
    free(temp);
    return deletedValue;
}


void traverse(struct Node* start) {
    if (start == NULL) {
        printf("Circular Singly Linked List is Empty.\n");
        return;
    }
    struct Node* temp = start;
    printf("Data Item in Circular Singly Linked List.\n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

void displayMenu() {
    printf("\n");
    printf("1. Insert At Begin\n");
    printf("2. Insert At End\n");
    printf("3. Delete From Begin\n");
    printf("4. Delete From End\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


int main() {
    int choice;
    struct Node* head = NULL;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        int value, deletedValue;
        switch (choice) {
            case 1:
                printf("Enter Value to Insert at Begin of Linked List: ");
                scanf("%d", &value);
                insertAtBegin(&head, value);
                break;
            case 2:
                printf("Enter Value to Insert at End of Linked List: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                deletedValue = deleteFromBegin(&head);
                if (deletedValue != -1)
                    printf("Data Item '%d' is Deleted from Begin of List\n", deletedValue);
                break;
            case 4:
                deletedValue = deleteFromEnd(&head);
                if (deletedValue != -1)
                    printf("Data Item '%d' is Deleted from End of List\n", deletedValue);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                printf("Exiting.....\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
