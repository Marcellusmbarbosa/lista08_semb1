#include <stdio.h>
#include <stdlib.h>

int pares(int *M, int l, int c) {
    int i, j, pares = 0, impares = 0;

    printf("Posições com números pares:\n");
    for(i = 0; i < l; i++) {
        for(j = 0; j < c; j++) {
            if(M[i*c + j] % 2 == 0) {
                printf("Linha %d, Coluna %d\n", i, j);
                pares++;
            } else {
                impares++;
            }
        }
    }

    printf("Número de posições pares: %d\n", pares);
    printf("Número de posições ímpares: %d\n", impares);

    return pares;
}

int main() {
    int l, c, i, j, *M;

    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &l, &c);

    M = (int*) malloc(l * c * sizeof(int));
    if(M == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os elementos da matriz:\n");
    for(i = 0; i < l; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &M[i*c + j]);
        }
    }

    pares(M, l, c);

    free(M);

    return 0;
}