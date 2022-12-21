#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#include "balanceamento.h"


int fatorBalanceamento(NO *raiz) {

    int alturaEsquerda = -1, alturaDireita = -1;

    if (raiz->esq != NULL) 
        alturaEsquerda = raiz->esq->altura;

    if (raiz->dir != NULL)
        alturaDireita = raiz->dir->altura;

    return (alturaEsquerda - alturaDireita);
}

void ajustaAltura(NO **raiz){
    int esq = -1, dir = -1;

    if ((*raiz)->esq != NULL)
        esq = (*raiz)->esq->altura;
    
    if ((*raiz)->dir != NULL)
        dir = (*raiz)->dir->altura;
    
    if (esq > dir)
        (*raiz)->altura = esq + 1;
    else
        (*raiz)->altura = dir + 1;
    
}


// function that performs the right rotation of an avl tree
void rotacaoDireita(NO **raiz){
    NO *aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    *raiz = aux;
    ajustaAltura(&(*raiz)->dir);
    ajustaAltura(raiz);
}

// function that performs the left rotation of an avl tree
void rotacaoEsquerda(NO **raiz){
    NO *aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    *raiz = aux;
    ajustaAltura(&(*raiz)->esq);
    ajustaAltura(raiz);
}

// function that performs the double right rotation of an avl tree
void rotacaoDuplaDireita(NO **raiz){
    rotacaoEsquerda(&(*raiz)->esq);
    rotacaoDireita(raiz);
}

// function that performs the double left rotation of an avl tree
void rotacaoDuplaEsquerda(NO **raiz){
    rotacaoDireita(&(*raiz)->dir);
    rotacaoEsquerda(raiz);
}


// function that performs the balancing of an avl tree
void gestaoBALANCEAMENTO(NO **raiz){
    int fb; // fator de balanceamento
    ajustaAltura(raiz);
    fb = fatorBalanceamento(*raiz);

    if (fb >= 2) {
        if (fatorBalanceamento((*raiz)->esq) > 0) {
            rotacaoDireita(raiz);
        } else {
            rotacaoDuplaDireita(raiz);
        }
    } else if (fb <= -2) {
        if (fatorBalanceamento((*raiz)->dir) < 0) {
            rotacaoEsquerda(raiz);
        } else {
            rotacaoDuplaEsquerda(raiz);
        }
    }

    /* printf("Dado: %d \n", (*raiz)->dado);
    printf("FB: %d\n", fb);
    printf("Altura: %d\n\n", (*raiz)->altura); */

}


