// ---------- Structs:

typedef struct NO {
	int dado;
	struct NO *esq; // NO esquerdo
	struct NO *dir; // NO direito
} NO;

typedef struct ARVORE{
	int tam; // Quantidade de NO presentes na árvore;
	NO *raiz; // Ponteiro que aponta para a raiz da árvore;
} ARVORE;

// ---------- Funções:

// Alocações
NO *alocaNO();
ARVORE *alocaArv();

// Apresentações
void preordem(NO *aux);
void inordem(NO *aux);
void posordem(NO *aux);

// Inserções de Valores
NO *inserir(ARVORE **arvore, NO *raiz, NO *novo);
void ler(NO *no);
void insereVetor(int *vetor, int tam, ARVORE **arvore);
void gestaoLER(ARVORE **arvore);

// Funções de buscas
NO *busca(NO *aux, int num);
void gestaoBUSCA(NO *raiz);
