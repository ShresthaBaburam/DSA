#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};


void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}


bool isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}


void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Data Item '%d' Added to Queue.\n", value);
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow.\n");
        return -1;
    }
    int dequeuedValue = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return dequeuedValue;
}


void traverse(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow.\n");
    } else {
        printf("\nThe Element(s) in Queue(front->rear) is/are:\n");
        struct Node* current = queue->front;
        while (current != NULL) {
            printf("%d\t", current->data);
            current = current->next;
        }
        printf("\n");
    }
}


int peek(struct Queue* queue, char frontRear) {
    if (isEmpty(queue)) {
        printf("Queue Underflow.\n");
        return -1;
    } else {
        if (frontRear == 'f') {
            return queue->front->data;
        } else {
            return queue->rear->data;
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
    struct Queue queue;
    initialize(&queue);

    int choice, value;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to Queue:");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(&queue));
                break;
            case 3:
                traverse(&queue);
                break;
            case 4:
                printf("Data Item in front of Queue: %d\n", peek(&queue, 'f'));
                break;
            case 5:
                printf("Data Item in rear of Queue: %d\n", peek(&queue, 'r'));
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
