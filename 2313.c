#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if (A + B <= C || A + C <= B || B + C <= A) {
        printf("Invalido\n");
    } else {
        if (A == B && B == C) {
            printf("Valido-Equilatero\n");
        } else if (A == B || A == C || B == C) {
            printf("Valido-Isoceles\n");
        } else {
            printf("Valido-Escaleno\n");
        }

        int maior = A;
        if (B > maior) maior = B;
        if (C > maior) maior = C;

        int somaQuadradosMenores;
        if (maior == A) {
            somaQuadradosMenores = B * B + C * C;
        } else if (maior == B) {
            somaQuadradosMenores = A * A + C * C;
        } else {
            somaQuadradosMenores = A * A + B * B;
        }

        if (maior * maior == somaQuadradosMenores) {
            printf("Retangulo: S\n");
        } else {
            printf("Retangulo: N\n");
        }
    }

    return 0;
}
