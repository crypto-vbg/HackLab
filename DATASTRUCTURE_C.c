#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void addNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void deleteNode(int position) {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    if (position == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    struct Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

void deleteData(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        temp = head;
    }
    while (temp != NULL) {
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}

void deleteList() {
    struct Node* temp = head;
    while (temp != NULL) {
        head = temp->next;
        free(temp);
        temp = head;
    }
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void invertList() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

void displayMemoryUsage() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int memory = count * sizeof(struct Node);
    printf("Total memory space occupied by the linked list: %d bytes\n", memory);
}

void deleteDataAndNext(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        temp = head;
    }
    while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            struct Node* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}


int main() {
    // Adding nodes to the linked list
    addNode(4);
    addNode(2);
    addNode(1);
    addNode(4);
    addNode(3);

    // Displaying the original linked list
    printf("Original linked list: ");
    displayList();

    // Deleting a node at position 2
    deleteNode(2);

    // Displaying the updated linked list
    printf("Linked list after deleting node at position 2: ");
    displayList();

    // Deleting all nodes with data value 4
    deleteData(4);

    // Displaying the updated linked list
    printf("Linked list after deleting nodes with data value 4: ");
    displayList();

    // Inverting the linked list
    invertList();

    // Displaying the updated linked list
    printf("Inverted linked list: ");
    displayList();

    // Deleting all nodes with data value 2 and their next node
    deleteDataAndNext(2);

    // Displaying the updated linked list
    printf("Linked list after deleting nodes with data value 2 and their next node: ");
    displayList();

    // Displaying the total memory occupied by the linked list
    displayMemoryUsage();

    // Deleting the entire linked list
    deleteList();

    return 0;
}
