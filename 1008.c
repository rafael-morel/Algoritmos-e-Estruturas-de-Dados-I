#include <stdio.h>

int main() {
    int numero, horas;
    double valor_hora, salario;
    scanf("%d", &numero);
    scanf("%d", &horas);
    scanf("%lf", &valor_hora);
    salario = horas * valor_hora;
    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2lf\n", salario);
    return 0;
}
