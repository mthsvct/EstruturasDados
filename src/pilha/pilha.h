// --------------- STRUCTS

typedef struct ITEM{
    int dado;
    struct ITEM *prox;
} ITEM;

typedef struct PILHA {
    int qnt;
    ITEM *topo;
} PILHA;

// ------------------------ FUNÇÕES

ITEM *alocaITEM();
PILHA *alocaPILHA();
PILHA *empilhar(PILHA *pilha, ITEM *novo);
ITEM *ler();
PILHA *gestaoEMPILHAR(PILHA *pilha);
ITEM *desempilhar(PILHA **pilha);
void gestaoDESEMPILHAR(PILHA **pilha);
PILHA *apresenta(PILHA **pilha);
