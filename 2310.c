#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int totalS = 0, totalB = 0, totalA = 0; 
    int totalS1 = 0, totalB1 = 0, totalA1 = 0; 

    for (int i = 0; i < N; i++) {
        char nome[100];
        scanf("%s", nome); 

        int S, B, A;
        scanf("%d %d %d", &S, &B, &A); 

        int S1, B1, A1;
        scanf("%d %d %d", &S1, &B1, &A1); 

        totalS += S;
        totalB += B;
        totalA += A;

        totalS1 += S1;
        totalB1 += B1;
        totalA1 += A1;
    }

    double percentualS = (double)totalS1 / totalS * 100;
    double percentualB = (double)totalB1 / totalB * 100;
    double percentualA = (double)totalA1 / totalA * 100;

    printf("Pontos de Saque: %.2lf %%.\n", percentualS);
    printf("Pontos de Bloqueio: %.2lf %%.\n", percentualB);
    printf("Pontos de Ataque: %.2lf %%.\n", percentualA);

    return 0;
}
