#include <stdio.h>
#include <stdbool.h>

struct Node {
    int x;
    int y;
    int steps;
};

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return 0;

    struct Node queue[64];
    int front = 0, rear = 0;
    bool visited[8][8] = {false};

    queue[rear++] = (struct Node){x1, y1, 0};
    visited[x1][y1] = true;

    while (front < rear) {
        struct Node current = queue[front++];

        for (int i = 0; i < 8; i++) {
            int new_x = current.x + dx[i];
            int new_y = current.y + dy[i];

            if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
                if (new_x == x2 && new_y == y2) {
                    return current.steps + 1;
                }
                if (!visited[new_x][new_y]) {
                    visited[new_x][new_y] = true;
                    queue[rear++] = (struct Node){new_x, new_y, current.steps + 1};
                }
            }
        }
    }

    return -1; 

int main() {
    char start[3], end[3];

    while (scanf("%s %s", start, end) == 2) {
        int x1 = start[0] - 'a';
        int y1 = start[1] - '1';
        int x2 = end[0] - 'a';
        int y2 = end[1] - '1';

        int moves = bfs(x1, y1, x2, y2);

        printf("To get from %s to %s takes %d knight moves.\n", start, end, moves);
    }

    return 0;
}
