# include <stdio.h>
# include <stdlib.h>

int main(){
    int n, i;
    printf("Digite o tamanho do vetor:");
    scanf("%d", &n);
    int v[n]; //Vetor alocado com tamanho n não pré-estabelecido
    
    for(i=0; i<n; i++) v[i] = i;
    for(i=0; i<n; i++) printf("%d\n", v[i]);

return 0;
}