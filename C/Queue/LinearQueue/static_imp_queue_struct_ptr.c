#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue {
    int queue[MAX_SIZE];
    int front, rear;
};


void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}


bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}


bool isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1 && queue->front == 0) || (queue->rear + 1 == queue->front);
}


void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = queue->rear + 1;
        queue->queue[queue->rear] = value;
        printf("Data Item '%d' Added to Queue.\n", value);
    }
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow.\n");
        return -1;
    } else {
        int dequeuedValue = queue->queue[queue->front];
        queue->front = queue->front + 1;
        return dequeuedValue;
    }
}


void traverse(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow.\n");
    } else {
        printf("\nThe Element(s) in Queue(rear->front) is/are:\n");
        int i = queue->rear;
        do {
            printf("%d\t", queue->queue[i]);
            i = i - 1;
        } while(i != queue->front - 1);
        printf("\n");
    }
}


int peek(struct Queue* queue, char *frontRear) {
    if (isEmpty(queue)) {
        printf("Queue Underflow.\n");
        return -1;
    } else {
        if (frontRear == "f"){
            return queue->queue[queue->front];
        } else{
            return queue->queue[queue->rear];
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
                int dequeuedValue = dequeue(&queue);
                if (dequeuedValue != -1){
                    printf("Data Item '%d' is Dequeued from Queue", dequeuedValue);
                }
                break;
            case 3:
                traverse(&queue);
                break;
            case 4:
                int frontValue = peek(&queue, "f");
                if (frontValue != -1){
                    printf("Data Item in front of Queue: %d", frontValue);
                }
                break;
            case 5:
                int rearValue = peek(&queue, "r");
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