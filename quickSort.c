#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

        quickSort(arr, 0, n - 1);

        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d,%.6f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
