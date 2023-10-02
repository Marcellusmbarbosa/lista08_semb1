#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, produtoEscalar = 0;
    int *x, *y;

    printf("Digite o número de elementos nos vetores: ");
    scanf("%d", &n);

    x = (int*) malloc(n * sizeof(int));
    y = (int*) malloc(n * sizeof(int));

    if(x == NULL || y == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor x: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("Digite os elementos do vetor y: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    for(i = 0; i < n; i++) {
        produtoEscalar += x[i] * y[i];
    }

    printf("O produto escalar dos vetores x e y é: %d\n", produtoEscalar);

    free(x);
    free(y);

    return 0;
}