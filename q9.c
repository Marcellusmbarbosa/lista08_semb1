#include <stdio.h>
#include <stdlib.h>

int **multiplicaM(int **A, int l1, int c1, int **B, int l2, int c2) {
    if (c1 != l2) {
        printf("O número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        return NULL;
    }

    int **C = (int **)malloc(l1 * sizeof(int *));
    for (int i = 0; i < l1; i++) {
        C[i] = (int *)malloc(c2 * sizeof(int));
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
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

    int **C = multiplicaM(A, linhas, colunas, B, linhas, colunas);
    printf("Matriz C (A x B):\n");
    printMatriz(C, linhas, colunas);

    return 0;
}