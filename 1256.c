#include <stdio.h>
int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int M, C;
        scanf("%d %d", &M, &C);
        int table[110][210];
        int count[110] = {0};
        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int index = key % M;
            table[index][count[index]++] = key;
        }
        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            for (int j = 0; j < count[i]; j++) {
                printf("%d -> ", table[i][j]);
            }
            printf("\\\n");
        }
        if (t < T - 1)
            printf("\n");
    }
    return 0;
}
