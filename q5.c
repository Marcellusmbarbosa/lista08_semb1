#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2) {
    int *v3 = malloc((n1 + n2) * sizeof(int));
    int i, j, k = 0;

    if(v3 == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    for(i = 0; i < n1; i++) {
        v3[k++] = v1[i];
    }

    for(i = 0; i < n2; i++) {
        int existe = 0;
        for(j = 0; j < n1; j++) {
            if(v2[i] == v1[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) {
            v3[k++] = v2[i];
        }
    }

    v3 = realloc(v3, k * sizeof(int));

    return v3;
}

int main() {
    int n1, n2, i, *v1, *v2, *v3;

    printf("Digite o número de elementos no vetor 1: ");
    scanf("%d", &n1);
    v1 = (int*) malloc(n1 * sizeof(int));
    printf("Digite os elementos do vetor 1: ");
    for(i = 0; i < n1; i++) {
        scanf("%d", &v1[i]);
    }

    printf("Digite o número de elementos no vetor 2: ");
    scanf("%d", &n2);
    v2 = (int*) malloc(n2 * sizeof(int));
    printf("Digite os elementos do vetor 2: ");
    for(i = 0; i < n2; i++) {
        scanf("%d", &v2[i]);
    }

    v3 = uniao(v1, n1, v2, n2);

    printf("A união dos vetores é: ");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    free(v1);
    free(v2);
    free(v3);

    return 0;
}