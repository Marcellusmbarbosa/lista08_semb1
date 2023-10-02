#include <stdio.h>
#include <stdlib.h>

int triangular(int *M, int l, int c) {
    for(int i = 0; i < l; i++) {
        for(int j = i + 1; j < c; j++) {
            if(M[i*c + j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int l, c;
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &l, &c);

    int *M = (int*) malloc(l * c * sizeof(int));
    if(M == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os elementos da matriz:\n");
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &M[i*c + j]);
        }
    }

    if(triangular(M, l, c)) {
        printf("A matriz é triangular inferior.\n");
    } else {
        printf("A matriz não é triangular inferior.\n");
    }

    free(M);

    return 0;
}