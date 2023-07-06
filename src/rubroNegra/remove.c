#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "remove.h"


int qnt_filhos(NO *no){
    // Função que contabiliza a quantidade de filhos que um determinado nó possui.
    int qnt = 0;
    if(no->dir != NULL){
        qnt++;
    }
    if(no->esq != NULL){
        qnt++;
    }
    return qnt;
}

NO *removerFolha(NO *raiz, NO **removido) {
    // Remove um nó que NÃO possui filhos.
    *removido = raiz;
    raiz = NULL;
    return raiz;
}

NO *removerPaiUm(NO *raiz, NO **removido) {
    // Remove um nó que possui um único filho.
    *removido = raiz;
    if( raiz->esq != NULL ){
        raiz = raiz->esq;
    } else {
        raiz = raiz->dir;
    }
    return raiz;
}

NO *maiorEsquerda(NO *raiz, NO *pai) {
    // Busca e retorna o Nó que possui o maior valor a esquerda de um tal nó.
    NO *resultado = NULL;
    if( raiz != NULL ){
        // Vai procurar o nó que não possui filho a direita.
        if( raiz->dir == NULL ){
            resultado = pai;
        } else {
            pai = raiz;
            resultado = maiorEsquerda(raiz->dir, pai);
        }
    }
    return resultado;
}

void troca(NO **maior, NO **raiz){
    int info;

    info = (*raiz)->dado;
    (*raiz)->dado = (*maior)->dado;
    (*maior)->dado = info; 
}

NO *removePaiDois(NO *raiz, NO **removido) {

    NO *maior = NULL;
    NO *pai;
    

    pai = raiz;
    pai = maiorEsquerda(raiz->esq, pai);

    if(pai == raiz)
        maior = pai->esq;
    else
        maior = pai->dir;
    
    // Troca de valores:
    troca(&maior, &raiz);


    if(pai != raiz)
        pai->dir = maior->esq;
    else 
        raiz->esq = maior->esq;
    
        
    maior->esq = NULL;
    *removido = maior;
    
    return raiz; }

// 50, 35, 100, 20, 10, 25, 22, 45, 40, 200, 150

NO *remover(NO *raiz, int num, NO **removido) {

    int qnt; // Quantidade de filhos;

    if( raiz != NULL ) {

        if( raiz->dado == num ){

            qnt = qnt_filhos(raiz);

            if( qnt == 0 ){
                // Eh folha.
                printf("FOLHA \n");
                raiz = removerFolha(raiz, removido);
            } else if( qnt == 1 ) {
                // Eh pai apenas de um Nó.
                // printf("Entrou aqui! \n");
                printf("1 FILHO \n");
                raiz = removerPaiUm(raiz, removido);
            } else {
                // Eh pai de DOIS nós.
                printf("2 FILHOS \n");
                raiz = removePaiDois(raiz, removido);
            }

        } else if( num < raiz->dado ) {
            raiz->esq = remover(raiz->esq, num, removido);
        } else if( num > raiz->dado ) {
            raiz->dir = remover(raiz->dir, num, removido);
        }
    }

    return raiz;
}


void gestaoREMOVE(NO **raiz){

    int num;
    NO *removido = NULL;

    printf("Digite o valor que deseja REMOVER: ");
	scanf("%d", &num);

    *raiz = remover(*raiz, num, &removido);

    if(removido != NULL) {
        printf("Valor removido com sucesso! \n");
        free(removido);
    } else {
        printf("O valor não foi encontrado, logo não foi possível remover.");
    }

}