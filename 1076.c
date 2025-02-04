#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, V, A;
        scanf("%d", &N);
        scanf("%d %d", &V, &A);
        int edge_exists[50][50] = {0};
        int count = 0;
        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int a = u < v ? u : v;
            int b = u < v ? v : u;
            if (!edge_exists[a][b]) {
                edge_exists[a][b] = 1;
                count++;
            }
        }
        printf("%d\n", count * 2);
    }
    return 0;
}
