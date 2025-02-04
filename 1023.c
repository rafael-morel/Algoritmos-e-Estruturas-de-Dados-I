#include <stdio.h>

int main() {
    int city_number = 0;
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        city_number++;
        if (city_number > 1) {
            printf("\n");
        }
        
        long long sum_X = 0, sum_Y = 0;
        int consumption[201] = {0}; // Initialize to zero
        
        for (int i = 0; i < N; i++) {
            int X, Y;
            scanf("%d %d", &X, &Y);
            sum_X += X;
            sum_Y += Y;
            int key = Y / X;
            consumption[key] += X;
        }
        
        printf("Cidade# %d:\n", city_number);
        int first = 1;
        for (int key = 0; key <= 200; key++) {
            if (consumption[key] > 0) {
                if (first) {
                    printf("%d-%d", consumption[key], key);
                    first = 0;
                } else {
                    printf(" %d-%d", consumption[key], key);
                }
            }
        }
        printf("\n");
        
        long long average_truncated = (sum_Y * 100LL) / sum_X;
        int integer_part = (int)(average_truncated / 100);
        int decimal_part = (int)(average_truncated % 100);
        printf("Consumo medio: %d.%02d m3.\n", integer_part, decimal_part);
    }
    
    return 0;
}
