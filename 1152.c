#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, cost;
} Edge;

int compare(const void *a, const void *b) {
    Edge *e1 = (Edge*) a;
    Edge *e2 = (Edge*) b;
    return e1->cost - e2->cost;
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    
    if (xroot == yroot)
        return;
    
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) == 2) {
        if (m == 0 && n == 0)
            break;
        
        Edge *edges = (Edge*) malloc(n * sizeof(Edge));
        long long totalCost = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost);
            totalCost += edges[i].cost;
        }
        
        qsort(edges, n, sizeof(Edge), compare);
        
        int *parent = (int*) malloc(m * sizeof(int));
        int *rank = (int*) calloc(m, sizeof(int));
        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }
        
        long long mstCost = 0;
        for (int i = 0; i < n; i++) {
            int set_u = find(parent, edges[i].u);
            int set_v = find(parent, edges[i].v);
            if (set_u != set_v) {
                mstCost += edges[i].cost;
                unionSets(parent, rank, set_u, set_v);
            }
        }
        
        printf("%lld\n", totalCost - mstCost);
        
        free(edges);
        free(parent);
        free(rank);
    }
    return 0;
}
