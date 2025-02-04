#include <stdio.h>
#include <stdlib.h>

#define MAXN 2001
#define MAX_EDGES_PER_NODE 2000

typedef struct {
    int edges[MAX_EDGES_PER_NODE];
    int size;
} AdjList;

AdjList original_adj[MAXN];
AdjList reversed_adj[MAXN];

int bfs(int start, AdjList adj[], int N) {
    int visited[MAXN] = {0};
    int queue[MAXN];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        for (int i = 0; i < adj[u].size; ++i) {
            int v = adj[u].edges[i];
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N, M;
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {
            break;
        }

        for (int i = 1; i <= N; ++i) {
            original_adj[i].size = 0;
            reversed_adj[i].size = 0;
        }

        for (int i = 0; i < M; ++i) {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            if (P == 1) {
                original_adj[V].edges[original_adj[V].size++] = W;
            } else {
                original_adj[V].edges[original_adj[V].size++] = W;
                original_adj[W].edges[original_adj[W].size++] = V;
            }
        }

        for (int u = 1; u <= N; ++u) {
            for (int j = 0; j < original_adj[u].size; ++j) {
                int v = original_adj[u].edges[j];
                reversed_adj[v].edges[reversed_adj[v].size++] = u;
            }
        }

        int original_reachable = bfs(1, original_adj, N);
        int reversed_reachable = bfs(1, reversed_adj, N);

        printf("%d\n", original_reachable && reversed_reachable ? 1 : 0);
    }

    return 0;
}
