#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int grid[101][101]; 

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = grid[i][j] + grid[i][j+1] + grid[i+1][j] + grid[i+1][j+1];
            printf(sum >= 2 ? "S" : "U");
        }
        printf("\n");
    }

    return 0;
}
