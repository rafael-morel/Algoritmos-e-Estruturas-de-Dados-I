#include <stdio.h>
#include <stdlib.h>

int bfs(int N, int x0, int y0, int x1, int y1, int directions[10][10][4]) {
    if (x0 == x1 && y0 == y1) return 0;

    int distance[10][10];
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            distance[x][y] = -1;
        }
    }

    int queue[100][2];
    int front = 0, rear = 0;

    distance[x0][y0] = 0;
    queue[rear][0] = x0;
    queue[rear][1] = y0;
    rear++;

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        if (directions[x][y][0] == 1) {
            int ny = y + 1;
            if (ny < N && distance[x][ny] == -1) {
                distance[x][ny] = distance[x][y] + 1;
                if (x == x1 && ny == y1) return distance[x][ny];
                queue[rear][0] = x;
                queue[rear][1] = ny;
                rear++;
            }
        }

        if (directions[x][y][1] == 1) {
            int ny = y - 1;
            if (ny >= 0 && distance[x][ny] == -1) {
                distance[x][ny] = distance[x][y] + 1;
                if (x == x1 && ny == y1) return distance[x][ny];
                queue[rear][0] = x;
                queue[rear][1] = ny;
                rear++;
            }
        }

        if (directions[x][y][2] == 1) {
            int nx = x - 1;
            if (nx >= 0 && distance[nx][y] == -1) {
                distance[nx][y] = distance[x][y] + 1;
                if (nx == x1 && y == y1) return distance[nx][y];
                queue[rear][0] = nx;
                queue[rear][1] = y;
                rear++;
            }
        }

        if (directions[x][y][3] == 1) {
            int nx = x + 1;
            if (nx < N && distance[nx][y] == -1) {
                distance[nx][y] = distance[x][y] + 1;
                if (nx == x1 && y == y1) return distance[nx][y];
                queue[rear][0] = nx;
                queue[rear][1] = y;
                rear++;
            }
        }
    }

    return distance[x1][y1] == -1 ? -1 : distance[x1][y1];
}

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        int directions[10][10][4] = {0};

        for (int i = 0; i < N; i++) {
            int y = N - 1 - i;
            for (int x = 0; x < N; x++) {
                for (int d = 0; d < 4; d++) {
                    scanf("%d", &directions[x][y][d]);
                }
            }
        }

        int P;
        scanf("%d", &P);
        for (int i = 0; i < P; i++) {
            int x0, y0, x1, y1;
            scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
            int res = bfs(N, x0, y0, x1, y1, directions);
            if (res == -1) {
                printf("Impossible\n");
            } else {
                printf("%d\n", res);
            }
        }

        printf("\n");
    }

    return 0;
}
