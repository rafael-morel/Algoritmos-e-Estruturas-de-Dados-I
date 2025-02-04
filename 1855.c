#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    char map[y][x + 1]; 
    for (int i = 0; i < y; i++) {
        scanf("%s", map[i]);
    }

    if (map[0][0] == '*') {
        printf("*\n");
        return 0;
    } else if (map[0][0] == '.') {
        printf("!\n");
        return 0;
    }

    int direction;
    char c = map[0][0];
    if (c == '>') {
        direction = 0;
    } else if (c == 'v') {
        direction = 1;
    } else if (c == '<') {
        direction = 2;
    } else { // '^'
        direction = 3;
    }

    int visited[y][x][4];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < 4; k++) {
                visited[i][j][k] = 0;
            }
        }
    }
    visited[0][0][direction] = 1;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int current_x = 0, current_y = 0;

    while (1) {
        int new_x = current_x + dx[direction];
        int new_y = current_y + dy[direction];

        if (new_x < 0 || new_x >= x || new_y < 0 || new_y >= y) {
            printf("!\n");
            return 0;
        }

        if (map[new_y][new_x] == '*') {
            printf("*\n");
            return 0;
        }

        int new_dir;
        char sym = map[new_y][new_x];
        if (sym == '>') {
            new_dir = 0;
        } else if (sym == 'v') {
            new_dir = 1;
        } else if (sym == '<') {
            new_dir = 2;
        } else if (sym == '^') {
            new_dir = 3;
        } else {
            new_dir = direction; // '.' case
        }

        if (visited[new_y][new_x][new_dir]) {
            printf("!\n");
            return 0;
        }

        visited[new_y][new_x][new_dir] = 1;
        current_x = new_x;
        current_y = new_y;
        direction = new_dir;
    }

    return 0;
}
