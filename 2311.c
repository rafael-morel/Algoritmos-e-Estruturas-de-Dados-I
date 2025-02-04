#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char nome[100];
        scanf("%s", nome);

        double GD;
        scanf("%lf", &GD);

        double notas[7];
        for (int j = 0; j < 7; j++) {
            scanf("%lf", &notas[j]);
        }

        double menor = notas[0], maior = notas[0];
        for (int j = 1; j < 7; j++) {
            if (notas[j] < menor) menor = notas[j];
            if (notas[j] > maior) maior = notas[j];
        }

        double soma = 0;
        for (int j = 0; j < 7; j++) {
            if (notas[j] != menor && notas[j] != maior) {
                soma += notas[j];
            }
        }

        double resultado = soma * GD;
        printf("%s %.2lf\n", nome, resultado);
    }

    return 0;
}
