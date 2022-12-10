// ---------- Structs:

typedef struct NO {
	int dado;
    int altura;
	struct NO *esq; // NO esquerdo
	struct NO *dir; // NO direito
} NO;

typedef struct ARVORE{
	int tam; // Quantidade de NO presentes na árvore;
	NO *raiz; // Ponteiro que aponta para a raiz da árvore;
} ARVORE;

// ---------- Protótipos: