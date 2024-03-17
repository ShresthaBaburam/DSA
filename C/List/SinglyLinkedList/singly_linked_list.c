#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid Position.\n");
        return;
    }

    if (position == 0) {
        insertAtBegin(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int currentPosition = 0;

    while (currentPosition < position - 1 && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid Position.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int deleteFromBegin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    struct Node* temp = *head;
    int deletedValue = temp->data;
    *head = (*head)->next;
    free(temp);
    return deletedValue;
}

int deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is Empty.\n");
        return -1;
    }
    if (position < 0) {
        printf("Invalid Position.\n");
        return -1;
    }
    if (position == 0) {
        return deleteFromBegin(head);
    }
    struct Node* current = *head;
    struct Node* previous = NULL;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position) {
        previous = current;
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Invalid Position.\n");
        return -1;
    }
    int deletedValue = current->data;
    previous->next = current->next;
    free(current);
    return deletedValue;
}

int deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is Empty.\n");
        return -1;
    }
    if ((*head)->next == NULL) {
        int deletedValue = (*head)->data;
        free(*head);
        *head = NULL;
        return deletedValue;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    int deletedValue = current->next->data;
    free(current->next);
    current->next = NULL;
    return deletedValue;
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayMenu() {
    printf("\n");
    printf("1. Insert At Begin\n");
    printf("2. Insert At Position\n");
    printf("3. Insert At End\n");
    printf("4. Delete From Begin\n");
    printf("5. Delete From Position\n");
    printf("6. Delete From End\n");
    printf("7. Traverse\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    struct Node* head = NULL;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        int value, position, deletedValue;
        switch (choice) {
            case 1:
                printf("Enter Value to Insert at Begin of Linked List: ");
                scanf("%d", &value);
                insertAtBegin(&head, value);
                break;
            case 2:
                printf("Enter Value to Insert into Position of Linked List: ");
                scanf("%d", &value);
                printf("Enter Position of Linked List: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 3:
                printf("Enter Value to Insert at End of Linked List: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 4:
                deletedValue = deleteFromBegin(&head);
                if (deletedValue != -1)
                    printf("Data Item '%d' is Deleted from Begin of List\n", deletedValue);
                break;
            case 5:
                printf("Enter Position of Linked List: ");
                scanf("%d", &position);
                deletedValue = deleteFromPosition(&head, position);
                if (deletedValue != -1)
                    printf("Data Item '%d' is Deleted from '%d' Position of List\n", deletedValue, position);
                break;
            case 6:
                deletedValue = deleteFromEnd(&head);
                if (deletedValue != -1)
                    printf("Data Item '%d' is Deleted from End of List\n", deletedValue);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                printf("Exiting.....\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
