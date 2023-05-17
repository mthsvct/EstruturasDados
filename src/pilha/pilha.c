#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pilha.h"

/* ----------------------------------- ALOCAÇÕES ----------------------------------- */

ITEM *alocaITEM() {
    ITEM *novo;
    novo = (ITEM *) malloc(sizeof(ITEM));
    novo->prox = NULL;
    return novo;
}

PILHA *alocaPILHA(){
    PILHA *nova;
    nova = (PILHA *) malloc(sizeof(PILHA));
    nova->qnt = 0;
    nova->topo = NULL;
    return nova;
}


/* ----------------------------------- EMPILHAR ----------------------------------- */

PILHA *empilhar(PILHA *pilha, ITEM *novo){
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->qnt++;
    return pilha; 
}

ITEM *ler(){
    ITEM *novo;
    novo = alocaITEM();
    printf("Digite o valor a ser inserido no novo item: ");
    scanf("%d", &novo->dado);
    return novo;
}

PILHA *gestaoEMPILHAR(PILHA *pilha){ return empilhar(pilha, ler()); }

/* ----------------------------------- DESEMPILHAR ----------------------------------- */

ITEM *desempilhar(PILHA **pilha){
    ITEM *novo = NULL;
    if( (*pilha)->topo != NULL ){
        novo = (*pilha)->topo;
        (*pilha)->topo = (*pilha)->topo->prox;
        novo->prox = NULL;
        (*pilha)->qnt--;
    }
    return novo;
}

void gestaoDESEMPILHAR(PILHA **pilha){
    ITEM *removido;
    removido = desempilhar(pilha);
    if(removido == NULL)
        printf("A pilha esta vazia!! \n");
    else{
        printf("%d Item desempilhado. \n", removido->dado);
        free(removido);
    }
}



/* ----------------------------------- APRESENTAÇÃO ----------------------------------- */

PILHA *apresenta(PILHA **pilha){

    ITEM *item = NULL;
    PILHA *aux;
    aux = alocaPILHA();

    do {
        item = desempilhar(pilha);

        if(item != NULL){
            printf("%d \n", item->dado);
            aux = empilhar(aux, item);
        }
        
        
    } while(item != NULL);
    return (aux);
}
