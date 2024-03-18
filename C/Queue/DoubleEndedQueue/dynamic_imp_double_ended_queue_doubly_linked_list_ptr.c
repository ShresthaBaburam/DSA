#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Deque {
    struct Node* front;
    struct Node* rear;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    if (deque == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}


int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}


void enqueueFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}


void enqueueRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}


void dequeueFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow.\n");
        exit(1);
    }
    int data = deque->front->data;
    struct Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL)
        deque->rear = NULL;
    else
        deque->front->prev = NULL;
    free(temp);
    printf("Dequeued Element from Front: %d\n", data);;
}


void dequeueRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow.\n");
        exit(1);
    }
    int data = deque->rear->data;
    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL)
        deque->front = NULL;
    else
        deque->rear->next = NULL;
    free(temp);
    printf("Dequeued Element from Rear: %d\n", data);;
}


void traverseDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow.\n");
        return;
    }
    struct Node* current = deque->front;
    printf("Data Item in Deque (Front->Rear)");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayMenu() {
    printf("\n");
    printf("1. Enqueue Front\n");
    printf("2. Enqueue Rear\n");
    printf("3. Dequeue Front\n");
    printf("4. Dequeue Rear\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


int main() {
    struct Deque* deque = createDeque();
    int choice;
    while (1) {
        displayMenu();
        int value;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to Queue[Front]:");
                scanf("%d", &value);
                enqueueFront(deque, value);
                break;
            case 2:
                printf("Enter the value to Queue[Rear]:");
                scanf("%d", &value);
                enqueueRear(deque, value);
                break;
            case 3:
                dequeueFront(deque);
                break;
            case 4:
                dequeueRear(deque);
                break;
            case 5:
                traverseDeque(deque);
                break;
            case 6:
                printf("Exiting....!");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}