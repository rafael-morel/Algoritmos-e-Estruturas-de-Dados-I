#include <stdio.h>

int main() {
    double N;
    scanf("%lf", &N);

    int notas100 = N / 100;
    N = N - notas100 * 100;
    int notas50 = N / 50;
    N = N - notas50 * 50;
    int notas20 = N / 20;
    N = N - notas20 * 20;
    int notas10 = N / 10;
    N = N - notas10 * 10;
    int notas5 = N / 5;
    N = N - notas5 * 5;
    int notas2 = N / 2;
    N = N - notas2 * 2;

    int moedas1 = N / 1;
    N = N - moedas1 * 1;
    int moedas50 = N / 0.50;
    N = N - moedas50 * 0.50;
    int moedas25 = N / 0.25;
    N = N - moedas25 * 0.25;
    int moedas10 = N / 0.10;
    N = N - moedas10 * 0.10;
    int moedas5 = N / 0.05;
    N = N - moedas5 * 0.05;
    int moedas1cent = N / 0.01;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notas100);
    printf("%d nota(s) de R$ 50.00\n", notas50);
    printf("%d nota(s) de R$ 20.00\n", notas20);
    printf("%d nota(s) de R$ 10.00\n", notas10);
    printf("%d nota(s) de R$ 5.00\n", notas5);
    printf("%d nota(s) de R$ 2.00\n", notas2);

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moedas1);
    printf("%d moeda(s) de R$ 0.50\n", moedas50);
    printf("%d moeda(s) de R$ 0.25\n", moedas25);
    printf("%d moeda(s) de R$ 0.10\n", moedas10);
    printf("%d moeda(s) de R$ 0.05\n", moedas5);
    printf("%d moeda(s) de R$ 0.01\n", moedas1cent);

    return 0;
}
