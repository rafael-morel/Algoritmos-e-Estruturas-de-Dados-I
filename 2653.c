#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

#define HASHSIZE 1000003  

Node *hash_table[HASHSIZE] = {NULL};

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash % HASHSIZE;
}

int is_unique(char *str) {
    unsigned long h = hash(str);
    Node *p = hash_table[h];
    while (p != NULL) {
        if (strcmp(p->str, str) == 0) {
            return 0; // Duplicate found
        }
        p = p->next;
    }
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        exit(1);
    }
    new_node->str = strdup(str);
    if (!new_node->str) {
        exit(1);
    }
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
    return 1; // Unique
}

char *read_line(FILE *fp) {
    int ch;
    size_t size = 16;
    size_t len = 0;
    char *buffer = malloc(size);
    if (!buffer) return NULL;

    while ((ch = fgetc(fp)) != EOF && ch != '\n') {
        if (len + 1 >= size) { // +1 for '\0'
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (!new_buffer) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
        buffer[len++] = ch;
    }
    buffer[len] = '\0';

    if (ch == EOF && len == 0) {
        free(buffer);
        return NULL;
    }

    return buffer;
}

void free_hash_table() {
    for (int i = 0; i < HASHSIZE; i++) {
        Node *p = hash_table[i];
        while (p != NULL) {
            Node *temp = p;
            p = p->next;
            free(temp->str);
            free(temp);
        }
    }
}

int main() {
    int count = 0;
    char *line;

    while ((line = read_line(stdin)) != NULL) {
        if (is_unique(line)) {
            count++;
        }
        free(line);
    }

    printf("%d\n", count);
    free_hash_table();

    return 0;
}
