#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* next;
};


struct CircularQueue {
    struct Node* rear;
};


void initialize(struct CircularQueue* cq) {
    cq->rear = NULL;
}


bool isEmpty(struct CircularQueue* cq) {
    return cq->rear == NULL;
}


void enqueue(struct CircularQueue* cq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode->data = value;
    if (isEmpty(cq)) {
        newNode->next = newNode;
        cq->rear = newNode;
    } else {
        newNode->next = cq->rear->next;
        cq->rear->next = newNode;
        cq->rear = newNode;
    }
    printf("Data Item '%d' is Enqueued to Queue.\n", value);
}


int dequeue(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* frontNode = cq->rear->next;
    int dequeuedValue = frontNode->data;
    if (cq->rear == frontNode) {
        cq->rear = NULL;
    } else {
        cq->rear->next = frontNode->next;
    }
    free(frontNode);
    return dequeuedValue;
}


void traverse(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue Underflow.\n");
        return;
    }
    struct Node* current = cq->rear->next;
    printf("Elements of the circular queue (front-> rear):");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != cq->rear->next);
    printf("\n");
}


int peek(struct CircularQueue* cq, char *frontRear) {
    if (isEmpty(cq)) {
        printf("Queue Underflow.\n");
        return -1;
    } else {
        if (frontRear == "f"){
            return cq->front->data;
        } else{
            return cq->rear->data;
        }
    }
}


void displayMenu() {
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Front\n");
    printf("5. Rear\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


int main() {
    int choice, value;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to Queue:");
                scanf("%d", &value);
                enqueue(&cq, value);
                break;
            case 2:
                int dequeuedValue = dequeue(&cq);
                if (dequeuedValue != -1){
                    printf("Data Item '%d' is Dequeued from Queue", dequeuedValue);
                }
                break;
            case 3:
                traverse(&cq);
                break;
            case 4:
                int frontValue = peek(&cq, "f");
                if (frontValue != -1){
                    printf("Data Item in front of Queue: %d", frontValue);
                }
                break;
            case 5:
                int rearValue = peek(&cq, "r");
                if (rearValue != -1){
                    printf("Data Item in rear of Queue: %d", rearValue);
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}