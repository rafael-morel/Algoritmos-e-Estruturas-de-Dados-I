#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int v;
    int p;
};

#define MAX_N 250

int main() {
    struct Edge adj[MAX_N][MAX_N];
    int adj_size[MAX_N];
    int service_sum[MAX_N];
    int dist[MAX_N];
    int visited[MAX_N];
    
    while (1) {
        int N, M, C, K;
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) {
            break;
        }

        for (int i = 0; i < MAX_N; i++) {
            adj_size[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adj[u][adj_size[u]].v = v;
            adj[u][adj_size[u]].p = p;
            adj_size[u]++;
            adj[v][adj_size[v]].v = u;
            adj[v][adj_size[v]].p = p;
            adj_size[v]++;
        }

        service_sum[C - 1] = 0;
        for (int i = C - 2; i >= 0; i--) {
            service_sum[i] = INT_MAX;
            for (int j = 0; j < adj_size[i]; j++) {
                if (adj[i][j].v == i + 1) {
                    service_sum[i] = service_sum[i + 1] + adj[i][j].p;
                    break;
                }
            }
        }

        int min_total = INT_MAX;
        for (int Z = 0; Z < C; Z++) {
            for (int i = 0; i < N; i++) {
                dist[i] = INT_MAX;
                visited[i] = 0;
            }
            dist[K] = 0;

            for (int iter = 0; iter < N; iter++) {
                int u = -1;
                int min_dist = INT_MAX;
                for (int i = 0; i < N; i++) {
                    if (!visited[i] && dist[i] < min_dist) {
                        min_dist = dist[i];
                        u = i;
                    }
                }
                if (u == -1) break;
                visited[u] = 1;
                if (u == Z) break;

                if (u < C && u != Z) continue;

                for (int j = 0; j < adj_size[u]; j++) {
                    int v = adj[u][j].v;
                    int p = adj[u][j].p;

                    if (v < C && v != Z) continue;

                    if (dist[v] > dist[u] + p) {
                        dist[v] = dist[u] + p;
                    }
                }
            }

            if (dist[Z] == INT_MAX) continue;
            if (service_sum[Z] == INT_MAX) continue;
            int total = dist[Z] + service_sum[Z];
            if (total < min_total) {
                min_total = total;
            }
        }

        printf("%d\n", min_total);
    }
    return 0;
}
