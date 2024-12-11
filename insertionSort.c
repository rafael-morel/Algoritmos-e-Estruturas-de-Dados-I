#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; 
    }
}

int main() {
    srand(time(NULL));

    int sizes[] = {20000, 40000, 60000, 80000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("n,tempo_segundos\n"); 

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];

        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            return 1;
        }

        generateRandomArray(arr, n);

        clock_t start = clock();

        insertionSort(arr, n);

        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d,%.6f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
