#include <stdio.h>

#define MAX_N 100005
#define LOG 20

int parent[MAX_N][LOG];
long long distance[MAX_N];
int depth[MAX_N];

void build_parent(int N) {
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i < N; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }

    for (int k = LOG - 1; k >= 0; k--) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = parent[u][k];
        }
    }

    if (u == v) {
        return u;
    }

    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }

    return parent[u][0];
}

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        depth[0] = 0;
        distance[0] = 0;
        parent[0][0] = 0;
        for (int k = 1; k < LOG; k++) {
            parent[0][k] = 0;
        }

        for (int i = 1; i < N; i++) {
            int Ai, Li;
            scanf("%d %d", &Ai, &Li);
            parent[i][0] = Ai;
            depth[i] = depth[Ai] + 1;
            distance[i] = distance[Ai] + Li;
        }

        build_parent(N);

        int Q;
        scanf("%d", &Q);
        for (int q = 0; q < Q; q++) {
            int S, T;
            scanf("%d %d", &S, &T);
            int ancestor = lca(S, T);
            long long res = distance[S] + distance[T] - 2 * distance[ancestor];
            printf("%lld", res);
            if (q < Q - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
