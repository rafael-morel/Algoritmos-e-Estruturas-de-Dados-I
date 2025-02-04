#include <stdio.h>

int main() {
    int codigo, quantidade;
    double preco;

    scanf("%d %d", &codigo, &quantidade);

    switch (codigo) {
        case 1: preco = 4.00; break;
        case 2: preco = 4.50; break;
        case 3: preco = 5.00; break;
        case 4: preco = 2.00; break;
        case 5: preco = 1.50; break;
    }

    printf("Total: R$ %.2lf\n", preco * quantidade);

    return 0;
}
