// ---------- Structs:

typedef struct NO {
	int dado;
	int profundidade;
	struct NO *esq; // NO esquerdo
	struct NO *dir; // NO direito
} NO;

typedef struct ARVORE{
	int tam; // Quantidade de NO presentes na árvore;
	int altura; // Altura da árvore;
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

// Funções de contagem
int countNodes(NO *root);
int soma(NO *raiz);
int altura(NO *raiz);
void profundidade(NO *raiz, int prof);

// Funções de apresentação de informações adicionais.
void preordem_infos(NO *raiz);
void inordem_infos(NO *raiz);
void posordem_infos(NO *raiz);
void selOrdem(ARVORE *arvore);