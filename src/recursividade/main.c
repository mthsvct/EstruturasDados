#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int busca( int *vetor, int i, int tamanho, int buscado ){
    int resultado = -1;
    if(i < tamanho){
        if( buscado == vetor[i] )
            resultado = i;
        else
            resultado = busca(vetor, i+1, tamanho, buscado);
    } 
    return resultado;
}

int soma(int i){
    int resultado = 0;

    /* printf("Valor de i: %d \n\n", i); */
    
    if (i > 0)
        resultado = i + soma(i-1);
    
    return resultado;
}

void testePonteiros(int **p){
    
    printf("---------------------------------- \n");
    printf("Valor de i: %d \n", **p);
    printf("Endereço guardado em p: %p \n", *p);
    printf("Endereço de &p: %p \n", p);
}


int main(){
    int i = 10;
    int *p = &i;
    //int vetor[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    printf("---------------------------------- \n");
    printf("Valor de i: %d \n", *p);
    printf("Endereço guardado em p: %p \n", p);
    printf("Endereço de &p: %p \n", &p);

    testePonteiros(&p);


    /* printf("Resultado final: %d \n", soma(5) );
    printf("Valor buscado esta na posicao: %d \n\n", busca(vetor, 0, 10, 20));
    */
    return 0;
}
