// ---------- Structs:
typedef struct NO {
	int dado;
    int altura;
	int profundidade;
	struct NO *esq; // NO esquerdo
	struct NO *dir; // NO direito
} NO;

typedef struct ARVORE{
	int tam; // Quantidade de NO presentes na árvore;
	int altura; // Altura da árvore;
	NO *raiz; // Ponteiro que aponta para a raiz da árvore;
} ARVORE;

// ---------- Protótipos:
NO *alocaNO();
ARVORE *alocaArv();
void preordem(NO *aux);
void inordem(NO *aux);
void posordem(NO *aux);
NO *inserir(ARVORE **arvore, NO *raiz, NO *novo);
void ler(NO *no);
void insereVetor(int *vetor, int tam, ARVORE **arvore);
void gestaoLER(ARVORE **arvore);
NO *busca(NO *aux, int num, int *passos);
void gestaoBUSCA(NO *raiz);
int countNodes(NO *root);
int soma(NO *raiz);
int altura(NO *raiz);
void profundidade(NO *raiz, int prof);
void preordem_infos(NO *raiz);
void inordem_infos(NO *raiz);
void posordem_infos(NO *raiz);
void selOrdem(ARVORE *arvore);