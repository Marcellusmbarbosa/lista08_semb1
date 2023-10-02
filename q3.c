# include <stdio.h>
# include <stdlib.h>

int *misterio(int n){
    int i, *vet = malloc(n*sizeof(int));
    vet[0] = 1;
    for(i=1; i<n; i++) vet[i] = i*vet[i-1];
return vet;
}

int main(){
    int i, n, *v;
    printf("Digite n:");
    scanf("%d", &n);
    v = misterio(n);
    for(i=0;i<n;i++) printf("%d\n", v[i]);
    free(v);
    return 0;
}