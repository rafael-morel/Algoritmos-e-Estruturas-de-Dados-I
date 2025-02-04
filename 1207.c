#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 2000
#define MAX_EDGES 500000
#define INF (1LL << 60)

typedef struct {
    int to;
    int rev;
    long long cap;
} Edge;

Edge edges[MAX_EDGES];
int edge_count = 0;
int adj[MAX_NODES][1000];
int adj_size[MAX_NODES] = {0};

int level[MAX_NODES];
int ptr[MAX_NODES];

void add_edge(int u, int v, long long cap) {
    edges[edge_count] = (Edge){v, edge_count + 1, cap};
    adj[u][adj_size[u]++] = edge_count++;
    edges[edge_count] = (Edge){u, edge_count - 1, 0};
    adj[v][adj_size[v]++] = edge_count++;
}

int q[MAX_NODES];
int q_head, q_tail;

int bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    q_head = q_tail = 0;
    q[q_tail++] = s;
    level[s] = 0;
    while (q_head < q_tail) {
        int u = q[q_head++];
        for (int i = 0; i < adj_size[u]; i++) {
            Edge e = edges[adj[u][i]];
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q[q_tail++] = e.to;
            }
        }
    }
    return level[t] != -1;
}

long long dfs(int u, int t, long long flow) {
    if (u == t) return flow;
    for (int *i = &ptr[u]; *i < adj_size[u]; (*i)++) {
        Edge *e = &edges[adj[u][*i]];
        if (e->cap > 0 && level[e->to] == level[u] + 1) {
            long long pushed = dfs(e->to, t, (flow < e->cap) ? flow : e->cap);
            if (pushed > 0) {
                e->cap -= pushed;
                edges[e->rev].cap += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

long long max_flow(int s, int t) {
    long long total = 0;
    while (bfs(s, t)) {
        memset(ptr, 0, sizeof(ptr));
        long long pushed;
        while ((pushed = dfs(s, t, INF)) > 0) {
            total += pushed;
        }
    }
    return total;
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        edge_count = 0;
        memset(adj_size, 0, sizeof(adj_size));

        int C[601];
        for (int j = 0; j < N; j++) {
            scanf("%d", &C[j]);
        }

        int P[401];
        for (int i = 0; i < M; i++) {
            scanf("%d", &P[i]);
        }

        int B[401];
        int vodka_list[401][601];
        for (int i = 0; i < M; i++) {
            scanf("%d", &B[i]);
            for (int k = 0; k < P[i]; k++) {
                scanf("%d", &vodka_list[i][k]);
                vodka_list[i][k]--; // Convert to 0-based index
            }
        }

        long long sum_positive = 0;
        for (int i = 0; i < M; i++) {
            sum_positive += B[i];
        }

        int source = 0;
        int sink = M + N + 1;

        // Connect source to categories
        for (int i = 0; i < M; i++) {
            add_edge(source, i + 1, B[i]);
        }

        // Connect vodkas to sink
        for (int j = 0; j < N; j++) {
            int vodka_node = M + 1 + j;
            add_edge(vodka_node, sink, C[j]);
        }

        // Connect categories to their vodkas
        for (int i = 0; i < M; i++) {
            int category_node = i + 1;
            for (int k = 0; k < P[i]; k++) {
                int vodka_id = vodka_list[i][k];
                int vodka_node = M + 1 + vodka_id;
                add_edge(category_node, vodka_node, INF);
            }
        }

        long long flow = max_flow(source, sink);
        long long ans = sum_positive - flow;
        printf("%lld\n", ans);
    }
    return 0;
}
