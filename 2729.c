#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_LENGTH 21

typedef struct Node {
    char item[MAX_LENGTH];
    struct Node* next;
} Node;

Node* createNode(const char* item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->item, item);
    newNode->next = NULL;
    return newNode;
}

void insertSorted(Node** head, const char* item) {
    Node* current = *head;
    while (current != NULL) {
        if (strcmp(current->item, item) == 0) {
            return; 
        }
        current = current->next;
    }

    Node* newNode = createNode(item);
    if (*head == NULL || strcmp((*head)->item, item) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL && strcmp(current->next->item, item) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s", current->item);
        current = current->next;
        if (current != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 

    for (int i = 0; i < N; i++) {
        char line[MAX_ITEMS * MAX_LENGTH];
        fgets(line, sizeof(line), stdin);

        Node* head = NULL;

        char* token = strtok(line, " \n");
        while (token != NULL) {
            insertSorted(&head, token);
            token = strtok(NULL, " \n");
        }

        printList(head);

        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
