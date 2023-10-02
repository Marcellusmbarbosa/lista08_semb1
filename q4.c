#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    double *vetor1, *vetor2, *soma;

    printf("Digite a dimensão do vetor: ");
    scanf("%d", &n);

    vetor1 = (double*) malloc(n * sizeof(double));
    vetor2 = (double*) malloc(n * sizeof(double));
    soma = (double*) malloc(n * sizeof(double));

    if(vetor1 == NULL || vetor2 == NULL || soma == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor 1: ");
    for(i = 0; i < n; i++) {
        scanf("%lf", &vetor1[i]);
    }

    printf("Digite os elementos do vetor 2: ");
    for(i = 0; i < n; i++) {
        scanf("%lf", &vetor2[i]);
    }

    for(i = 0; i < n; i++) {
        soma[i] = vetor1[i] + vetor2[i];
    }

    printf("A soma dos vetores é: ");
    for(i = 0; i < n; i++) {
        printf("%.2lf ", soma[i]);
    }
    printf("\n");

    free(vetor1);
    free(vetor2);
    free(soma);

    return 0;
}