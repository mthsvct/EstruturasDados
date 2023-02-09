#include <stdio.h>
#include <stdlib.h>

struct ArvBin{
	int Info;
	struct ArvBin *Esq, *Dir;	
};

int remove(struct ArvBin **Raiz, int Elem)
{ int Achou = 1;
	
	if(*Raiz != NULL)
	{ 
		if((*Raiz)->Info == Elem)
	  	{  
			struct ArvBin *Aux;
		 	Aux = *Raiz;
			if (ehfolha(*Raiz))
				*Raiz = NULL;
			else if(sotemUmFilho(*Raiz,&NoFilho)==1)
		        	*Raiz = NoFilho;
				 else {
					   *Raiz = Aux->Esq;
						NoMaior = maior(*Raiz);
						NoMaior->Dir = Aux->Dir;
				}
			free(Aux);	
		
	   }
	  	else if((*Raiz)->Info < Elem)
			      Achou = remove(&((*Raiz)->Esq),Elem);
			else Achou = remove(&((*Raiz)->Dir),Elem);

			
		
	}
	
	return(Achou);
}

	
	
int main()
{ struct ArvBin *Raiz;
	
  Raiz = NULL;
  remove(&Raiz,300);
	
return 0;	
}