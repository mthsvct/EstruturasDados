// Funções:
int qnt_filhos(NO *no);
NO *removerFolha(NO *raiz, NO **removido);
NO *removerPaiUm(NO *raiz, NO **removido);
NO *maiorEsquerda(NO *raiz, NO *pai);
void troca(NO **maior, NO **raiz);
NO *removePaiDois(NO *raiz, NO **removido);
NO *remover(NO *raiz, int num, NO **removido);
void gestaoREMOVE(NO **raiz);