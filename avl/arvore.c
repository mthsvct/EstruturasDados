#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arvore.h"
#include "balanceamento.c"

/* ----------------------------------- ALOCAÇÕES ----------------------------------- */

NO *alocaNO(){
    // Função que realiza a alocação de um novo Nó da árvore.
    NO *novo;
    novo = (NO *) malloc(sizeof(NO));
    novo->dir = NULL; // Os ponteiros devem ser iniciados apontando para NULL.
    novo->esq = NULL;
	novo->altura = -1;
	novo->profundidade = -1;
    return novo;
}

ARVORE *alocaArv(){
    // Função que realiza a alocação de uma nova Árvore.
    ARVORE *nova;
    nova = (ARVORE *) malloc(sizeof(ARVORE));
    nova->raiz = NULL; // Como a raiz é um ponteiro deve se iniciar apontando para NULL;
    nova->tam = 0;     // O tamanho é uma variável que armazenará a quantidade de Nós que aquela árvore possui, logo deve se iniciar com 0. 
    nova->altura = 0; // A altura é uma variável que armazenará a altura
	return nova;
}

/* ----------------------------------- APRESENTAÇÕES ----------------------------------- */

void preordem(NO *aux) {
    // Função que apresenta todos os NOs da árvore em Pré-Ordem
	// Raiz, esquerda, direita;
	if(aux != NULL){
		printf("%d ", aux->dado);
		preordem(aux->esq);
		preordem(aux->dir);
	} 
}

void inordem(NO *aux) {
    // Função que apresenta todos os NOs da árvore em IN-Ordem
	// esquerda, Raiz, direita;
	if(aux != NULL){
		inordem(aux->esq);
		printf("%d ", aux->dado);
		inordem(aux->dir);
	} 
}

void posordem(NO *aux) {
    // Função que apresenta todos os NOs da árvore em Pós-Ordem
	// esquerda, direita, raiz;
	if(aux != NULL){
		posordem(aux->esq);
		posordem(aux->dir);
		printf("%d ", aux->dado);
	} 
}

/* ----------------------------------- INSERÇÕES ----------------------------------- */

NO *inserir(ARVORE **arvore, NO *raiz, NO *novo){

    if( raiz == NULL ){
		// arvore não possue uma raiz, então o novo é a nova raiz.
		raiz = novo; 
		(*arvore)->tam = (*arvore)->tam + 1;

    } else if( novo->dado < raiz->dado ) {
		// Se o dado que está no novo Nó é menor que o comparado, então ele deve ser comparado ou inserido a esquerda.
        raiz->esq = inserir(arvore, raiz->esq, novo);
        
    } else if( novo->dado > raiz->dado ){
		// Se o dado que está no novo Nó é maior que o comparado, então ele deve ser comparado ou inserido a direita.
        raiz->dir = inserir(arvore, raiz->dir, novo);
    }

	gestaoBALANCEAMENTO(&raiz);
    return raiz;
}

void ler(NO *no){
	// Função que ler os dados do novo NO;
	printf("Digite um numero para o novo NO: ");
	scanf("%d", &(no->dado)); 
}

void insereVetor(int *vetor, int tam, ARVORE **arvore){
	int i;
	NO *novo;
	for(i=0; i<tam; i++){
		novo = alocaNO();
		novo->dado = vetor[i];
		(*arvore)->raiz = inserir(arvore, (*arvore)->raiz, novo);
		printf("-----------------------------------\n");
	}
}

void gestaoLER(ARVORE **arvore) {
	// Função que aloca espaço para um novo NO e chama a função de leitura.
	NO *novo;
	novo = alocaNO();
	ler(novo);
	(*arvore)->raiz = inserir(arvore, (*arvore)->raiz, novo); 
}

/* ----------------------------------- BUSCA ----------------------------------- */

NO *busca(NO *aux, int num){
	
	// Função que busca um Nó na árvore a partir de um valor.

	NO *resultado;
	resultado = NULL;

	if( aux != NULL ) {
		if( aux->dado == num ){
			resultado = aux;
		} else if( num < aux->dado ){
			resultado = busca(aux->esq, num);
		} else if( num > aux->dado ) {
			resultado = busca(aux->dir, num);
		}
	}

	return resultado;
}

void gestaoBUSCA(NO *raiz){

	// Função que solicita que o usuário digite o valor a ser buscado.

	int num;
	NO *encontrado;

	printf("Digite o valor que deseja buscar: ");
	scanf("%d", &num);

	encontrado = busca(raiz, num);

	if(encontrado != NULL){
		printf("Número encontrado! \n");
	} else {
		printf("O número NAO foi encontrado! \n");
	}

}


int countNodes(NO *root) {
	// Função que conta a quantidade de Nós na arvore
	if (root == NULL)
		return 0;
	return (1 + countNodes(root->esq) + countNodes(root->dir));
}


int soma(NO *raiz) {
	// functio que soma todos os nodes na arvore
	int valor = 0;
	if(raiz != NULL){
		valor = raiz->dado + soma(raiz->esq); 
		valor = valor + soma(raiz->dir);
	}
	return valor;
}


// function para calcular a altura de uma árvore binária

// altura é a distância da raiz para o nó mais profundo.
// profundidade de um nó é a distância da raiz até aquele nó especifico.
// uma árvore possui uma altura.
// cada nó possui uma profundidade.

int altura(NO *raiz) {
	int esq = 0, dir = 0, alt = 0;

	if (raiz != NULL){
		esq = altura(raiz->esq);
		dir = altura(raiz->dir);
		if (esq > dir){
			alt = esq + 1;
		} else {
			alt = dir + 1;
		}
	}

	return alt;
}


// função que adiciona a profundidade de todos os nós de uma árvore
void profundidade(NO *raiz, int prof) {
	/*
		Nesta função cada nó recebe a profundidade da árvore.
		Primeiro é atribuido a profundidade do nó e em seguida é chamado a função recursivamente 
		para os nós da esquerda e da direita. 
	*/
	if(raiz != NULL){
		raiz->profundidade = prof;
		profundidade(raiz->esq, prof+1);
		profundidade(raiz->dir, prof+1);
	}
}


void preordem_infos(NO *raiz) {
	// Função que imprime os dados de todos os nós da árvore em pré-ordem + informações adicionai.
	if(raiz != NULL){
		printf("Dado: %d | Profundidade: %d \n", raiz->dado, raiz->profundidade);
		preordem_infos(raiz->esq);
		preordem_infos(raiz->dir);
	}	
}

void inordem_infos(NO *raiz) {
	// Função que imprime os dados de todos os nós da árvore em ordem + informações adicionais.
	if(raiz != NULL){
		inordem_infos(raiz->esq);
		printf("Dado: %d | Profundidade: %d \n", raiz->dado, raiz->profundidade);
		inordem_infos(raiz->dir);
	}	
}

void posordem_infos(NO *raiz) {
	// Função que imprime os dados de todos os nós da árvore em pós-ordem + informações adicionais.
	if(raiz != NULL){
		posordem_infos(raiz->esq);
		posordem_infos(raiz->dir);
		printf("Dado: %d | Profundidade: %d \n", raiz->dado, raiz->profundidade);
	}	
}

void selOrdem(ARVORE *arvore){
	int op;

	printf("Escolha a ordem de impressão: \n");
	printf("1 - Pré-ordem \n");
	printf("2 - Em ordem \n");
	printf("3 - Pós-ordem \n");

	printf("Digite: ");
	scanf("%d", &op);

	printf("\n\n");

	switch(op){

		case 1:
			preordem_infos(arvore->raiz);
			break;

		case 2:
			inordem_infos(arvore->raiz);
			break;

		case 3:
			posordem_infos(arvore->raiz);
			break;

		default:
			printf("Opção inválida! Digite novamente. \n");
			selOrdem(arvore);
			break;
	}

}