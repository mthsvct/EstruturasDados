#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "geraVetor.h"

// Função que aloca um vetor de tamanho tam
int *alocaVetor(int tam){
    int *vetor;
    vetor = (int *) malloc(tam * sizeof(int));
    return vetor;
}

// Função que gera um vetor de números aleatórios da quantidade X passada por parâmetro:
void geraVetor(int *vetor, int x){
    int i;
    for(i = 0; i < x; i++)
        vetor[i] = rand() % 100000;  
}

// Função que realiza a chamada das funções.
void adicionaAleatorios(ARVORE **arvore) {
    int *vetor = NULL;
    int tam;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = alocaVetor(tam);
    geraVetor(vetor, tam);
    insereVetor(vetor, tam, arvore);
}

// Function that generates a txt file with X random numbers
void geraTxt(){
    int i;
    FILE *arq, *tamArq;
    int *vetor;
    int tam;

    arq = fopen("numeros.txt", "w");
    tamArq = fopen("tamanho.txt", "w");
    
    if(arq == NULL || tamArq == NULL)
        printf("Erro ao abrir o arquivo!");
    else {

        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tam);

        fprintf(tamArq, "%d\n", tam);

        vetor = alocaVetor(tam);
        geraVetor(vetor, tam);

        for (i = 0; i<tam; i++)
            fprintf(arq, "%d\n", vetor[i]);
        
    }
}

// Function that reads a txt file and adds the numbers to the tree
void lerTxt(ARVORE **arvore){
    FILE *arq, *tamArq;
    int *vetor;
    int tam;
    int i = 0;

    arq = fopen("numeros.txt", "r");
    tamArq = fopen("tamanho.txt", "r");

    if(arq == NULL || tamArq == NULL)
        printf("Erro ao abrir o arquivo!");
    else {

        fscanf(tamArq, "%d", &tam);

        vetor = alocaVetor(tam);
        
        for (i = 0; i<tam; i++)
            fscanf(arq, "%d", &vetor[i]);

        insereVetor(vetor, tam, arvore);
    }
}