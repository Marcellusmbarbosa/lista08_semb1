#include <stdio.h>
#include <stdlib.h>

int **somaMatriz(int **A, int l1, int c1, int **B, int l2, int c2) {
    if (l1 != l2 || c1 != c2) {
        printf("As matrizes devem ter as mesmas dimensões.\n");
        return NULL;
    }

    int **C = (int **)malloc(l1 * sizeof(int *));
    for (int i = 0; i < l1; i++) {
        C[i] = (int *)malloc(c1 * sizeof(int));
        for (int j = 0; j < c1; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

void printMatriz(int **M, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas e colunas da matriz quadrada: ");
    scanf("%d", &linhas);
    colunas = linhas;

    int **A = (int **)malloc(linhas * sizeof(int *));
    int **B = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        A[i] = (int *)malloc(colunas * sizeof(int));
        B[i] = (int *)malloc(colunas * sizeof(int));
    }

    printf("Digite os valores para a matriz A:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os valores para a matriz B:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("Matriz A:\n");
    printMatriz(A, linhas, colunas);
    printf("Matriz B:\n");
    printMatriz(B, linhas, colunas);

    int **C = somaMatriz(A, linhas, colunas, B, linhas, colunas);
    printf("Matriz C (A + B):\n");
    printMatriz(C, linhas, colunas);

    return 0;
}
