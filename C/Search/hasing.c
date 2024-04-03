#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insert(int key, struct Node* hashTable[]) {
    int index = key % SIZE;
    struct Node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}


int search(int key, struct Node* hashTable[]) {
    int index = key % SIZE;
    struct Node* current = hashTable[index];
    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    struct Node* hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
    insert(10, hashTable);
    insert(20, hashTable);
    insert(30, hashTable);
    int key1 = 20;
    if (search(key1, hashTable)) {
        printf("%d found in the hash table.\n", key1);
    } else {
        printf("%d not found in the hash table.\n", key1);
    }

    int key2 = 40;
    if (search(key2, hashTable)) {
        printf("%d found in the hash table.\n", key2);
    } else {
        printf("%d not found in the hash table.\n", key2);
    }
    return 0;
}
