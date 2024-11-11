#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, char* name) {
    Node* newNode = createNode(name);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    
    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%s", node->name);
        if (node->next != NULL) {
            printf(" ");
        }
        node = node->next;
    }
    printf("\n");
}

void freeList(Node* node) {
    Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    char currentFriends[500], newFriends[500], suggestedFriend[50];
    
    fgets(currentFriends, sizeof(currentFriends), stdin);
    
    fgets(newFriends, sizeof(newFriends), stdin);
    
    fgets(suggestedFriend, sizeof(suggestedFriend), stdin);
    
    suggestedFriend[strcspn(suggestedFriend, "\n")] = 0;

    Node* currentList = NULL;

    char* token = strtok(currentFriends, " \n");
    while (token != NULL) {
        append(&currentList, token);
        token = strtok(NULL, " \n");
    }

    Node* newList = NULL;
    token = strtok(newFriends, " \n");
    while (token != NULL) {
        append(&newList, token);
        token = strtok(NULL, " \n");
    }

    if (strcmp(suggestedFriend, "nao") == 0) {
        Node* temp = currentList;
        if (temp == NULL) {
            currentList = newList;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newList;
        }
    } else {
        Node* temp = currentList;
        Node* prev = NULL;
        while (temp != NULL && strcmp(temp->name, suggestedFriend) != 0) {
            prev = temp;
            temp = temp->next;
        }
        
        if (temp != NULL) {
            if (prev == NULL) {
                Node* lastNew = newList;
                while (lastNew->next != NULL) {
                    lastNew = lastNew->next;
                }
                lastNew->next = currentList;
                currentList = newList;
            } else {
                prev->next = newList;
                Node* lastNew = newList;
                while (lastNew->next != NULL) {
                    lastNew = lastNew->next;
                }
                lastNew->next = temp;
            }
        } else {
            Node* temp = currentList;
            if (temp == NULL) {
                currentList = newList;
            } else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newList;
            }
        }
    }

    printList(currentList);
    
    freeList(currentList);

    return 0;
}
