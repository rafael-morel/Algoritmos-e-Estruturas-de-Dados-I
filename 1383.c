#include <stdio.h>
#include <stdbool.h>

bool check_sudoku(int sudoku[9][9]) {
    int i, j, valorL, valorC, valorQ;

    for (i = 0; i < 9; i++) {
        bool check_linha[9] = {0};
        bool check_coluna[9] = {0};
        bool check_quadrante[9] = {0};

        for (j = 0; j < 9; j++) {
            valorL = sudoku[i][j];
            valorC = sudoku[j][i];
            valorQ = sudoku[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3];

            // Verifica se o valor já foi visto na linha, coluna ou quadrante
            if (check_linha[valorL - 1] || check_coluna[valorC - 1] || check_quadrante[valorQ - 1]) {
                return false;
            }

            // Marca os valores como vistos
            check_linha[valorL - 1] = true;
            check_coluna[valorC - 1] = true;
            check_quadrante[valorQ - 1] = true;
        }
    }
    return true;
}

int main() {
    int n, i, j, k;

    scanf("%d", &n);  // Lê o número de matrizes

    for (i = 0; i < n; i++) {
        int sudoku[9][9];
        
        // Lê a matriz 9x9
        for (j = 0; j < 9; j++) {
            for (k = 0; k < 9; k++) {
                scanf("%d", &sudoku[j][k]);
            }
        }

        // Verifica se a matriz é uma solução válida de Sudoku
        printf("Instancia %d\n", i + 1);
        if (check_sudoku(sudoku)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
