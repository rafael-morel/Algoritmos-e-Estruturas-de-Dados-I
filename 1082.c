#include <stdio.h>
#include <stdlib.h>

int components[26][26];
int component_sizes[26];

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return arg1 - arg2;
}

int compare_components(const void *a, const void *b) {
    int index_a = *(const int*)a;
    int index_b = *(const int*)b;
    return components[index_a][0] - components[index_b][0];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int t = 1; t <= N; t++) {
        int V, E;
        scanf("%d %d", &V, &E);

        int parent[26];
        int size[26];
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        for (int e = 0; e < E; e++) {
            char u[2], v[2];
            scanf("%s %s", u, v);
            int x = u[0] - 'a';
            int y = v[0] - 'a';

            int root_x = x;
            while (parent[root_x] != root_x) {
                root_x = parent[root_x];
            }
            int root_y = y;
            while (parent[root_y] != root_y) {
                root_y = parent[root_y];
            }

            if (root_x != root_y) {
                if (size[root_x] < size[root_y]) {
                    parent[root_x] = root_y;
                    size[root_y] += size[root_x];
                } else {
                    parent[root_y] = root_x;
                    size[root_x] += size[root_y];
                }
            }
        }

        for (int i = 0; i < V; i++) {
            int root = i;
            while (parent[root] != root) {
                root = parent[root];
            }
            int current = i;
            while (parent[current] != root) {
                int next = parent[current];
                parent[current] = root;
                current = next;
            }
        }

        int component_count = 0;
        for (int i = 0; i < V; i++) {
            if (parent[i] == i) { // i is a root
                component_sizes[component_count] = 0;
                for (int j = 0; j < V; j++) {
                    if (parent[j] == i) {
                        components[component_count][component_sizes[component_count]] = j;
                        component_sizes[component_count]++;
                    }
                }
                qsort(components[component_count], component_sizes[component_count], sizeof(int), compare_ints);
                component_count++;
            }
        }

        int component_order[26];
        for (int i = 0; i < component_count; i++) {
            component_order[i] = i;
        }
        qsort(component_order, component_count, sizeof(int), compare_components);

        printf("Case #%d:\n", t);
        for (int i = 0; i < component_count; i++) {
            int comp_idx = component_order[i];
            for (int j = 0; j < component_sizes[comp_idx]; j++) {
                printf("%c,", components[comp_idx][j] + 'a');
            }
            printf("\n");
        }
        printf("%d connected components\n\n", component_count);
    }

    return 0;
}
