#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "pilha.c"


//----------------------------------------------------------//
// Apresentação de texto repetidos:

void ast(){ printf("-------------------------------------------------------------\n"); }

int menu(){

	// FUNÇÃO QUE APRESENTA UM MENU.

	int op;
	printf("\n\n");
	
	ast();
	printf("\t\t\tMENU PRINCIPAL:\n");
	ast();
	
	printf("[1] - EMPILHAR NOVO ITEM\n");
	printf("[2] - DESEMPILHAR ITEM\n");
	printf("[3] - APRESENTAR ITENS\n");
	printf("[0] - Sair\n");

	ast();
	printf("SELECIONE A OPCAO DE DESEJADA: ");
	scanf("%d", &op);
	ast();

	printf("\n\n");

	return op; }

//----------------------------------------------------------//
// FUNÇÃO MAIN:

int main(){

	int op;
	PILHA *pilha;

	srand(time(NULL));

	do{

		op = menu();

		switch(op){

			case 0:
				// ENCERRAR O PROGRAMA;
				ast();
				printf("\t\tPrograma encerrado!\n");
				ast();
				break;

			case 1:
				// FUNÇÃO QUE LER A RAIZ
				pilha = gestaoEMPILHAR(pilha);
				break;
			
			case 2:
				// FUNÇÃO QUE LER A RAIZ
				gestaoDESEMPILHAR(&pilha);
				break;
			
			case 3:
				// FUNÇÃO QUE LER A RAIZ
				pilha = apresenta(&pilha);
				break;

			default:
				// MENSAGEM DE ERRO
				ast();
				printf("Valor inválido, digite novamente:\n");
				ast();
				break;
		}

	} while(op != 0);

	return 0; 
}