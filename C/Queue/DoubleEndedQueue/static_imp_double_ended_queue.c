#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1, rear = -1;


void enqueueFront(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow.\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        if (front != 0) {
            front--;
        } else {
            for (int i = rear; i >= front; i--) {
                deque[i + 1] = deque[i];
            }
            rear++;
            front++;
        }
    }
    deque[front] = data;
}


void enqueueRear(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow.\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        if (rear != MAX_SIZE - 1) {
            rear++;
        } else {
            for (int i = front; i <= rear; i++) {
                deque[i - 1] = deque[i];
            }
            rear--;
            front--;
        }
    }
    deque[rear] = data;
}


void dequeueFront() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow.\n");
        return;
    }
    int data;
    if (front == rear) {
        data = deque[front];
        front = rear = -1;
    } else {
        data = deque[front];
        front++;
    }
    printf("Dequeued Element from Front: %d\n", data);
}


void dequeueRear() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
        return;
    }
    int data;
    if (front == rear) {
        data = deque[rear];
        front = rear = -1;
    } else {
        data = deque[rear];
        rear--;
    }
    printf("Dequeued Element from Rear: %d\n", data);
}


void traverse() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Data Item in Double Ended Queue(Front->Rear):");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
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
    int choice;
    while (1) {
        displayMenu();
        int value;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to Queue[Front]:");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 2:
                printf("Enter the value to Queue[Rear]:");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                traverse();
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
