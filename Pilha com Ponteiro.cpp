#include <stdio.h>
#include <stdlib.h>

struct pilha 
	{
		int topo;
		int capacidade;
		float *proximoelemento;
	};
	  
	  void cria_pilha(struct pilha *ponteiro, int qtde) 
        {
        	ponteiro -> proximoelemento=(float*) malloc(qtde*sizeof(float));
        	ponteiro -> topo=-1;
        	ponteiro -> capacidade=qtde;
		}
		
      void push_pilha(struct pilha *ponteiro, float valor)
      {
      	ponteiro -> topo++;
      	ponteiro -> proximoelemento [ponteiro->topo]=valor;
	  }
	  
	  float pop_pilha(struct pilha *ponteiro)
	  {
	  	float aux=ponteiro -> proximoelemento [ponteiro->topo];
	  	ponteiro-> topo--;
	  	return aux;
	  }
	  
	  int pilha_vazia(struct pilha *ponteiro)
	  {
	  	if(ponteiro -> topo==-1)
	  	return 1;
	  	else 
	  	return 0;
	  }
	  
	   int pilha_cheia(struct pilha *ponteiro)
	   {
	   	if (ponteiro->topo==ponteiro->capacidade-1)
	   	return 1;
	   	else
	   	return 0;
	   }
	   
	   float mostrartopo(struct pilha *ponteiro)
	   {
	   	return ponteiro -> proximoelemento[ponteiro->topo];
	   }
	   
	   void mostrarpilha (struct pilha *ponteiro)
	   {
	   	 for (int conta=ponteiro -> topo;conta>=0;conta--)
			printf("%.2f \n", ponteiro -> proximoelemento[conta]);
		 
	   }     
	 
	  int main(void)
{
	  	struct pilha minhapilha;
	  	int opcao, tamanho;
	  	float novovalor;
	  	printf("\nInforme o tamanho da pilha: ");
	  	scanf("%d", &tamanho);
	  	cria_pilha(&minhapilha,tamanho);
	
	  
    while( 1 )
    {
		system("cls");
		printf("Operacoes com pilha\n\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Mostrar Topo\n");
		printf("4 - Mostrar Pilha\n");
		printf("5 - Sair\n");
		printf("\nEscolha uma opcao? ");
		scanf("%d", &opcao);
		switch(opcao)
	
	{ 
			case 1: 
			if(pilha_cheia(&minhapilha)==1)
			printf("\nPilha esta Lotada. \n");
			
			else
			{
				printf("\nDigite o valor: ");
		    	scanf("%f",&novovalor);
		    	push_pilha(&minhapilha,novovalor);
		    }
  			  break;
			
			case 2:
			if(pilha_vazia(&minhapilha)==1)
			printf("\nPilha esta Vazia. \n");
			
			else
			{
		    	pop_pilha(&minhapilha);
		    }

			  break;
			  
			case 3:
				if(pilha_vazia(&minhapilha)==1)
			printf("\nPilha esta Vazia. \n");
			
			else
			{
			novovalor=mostrartopo(&minhapilha);
			printf("\nTopo: %2.f \n",novovalor);	
				}	


              break;
			case 4:
					if(pilha_vazia(&minhapilha)==1)
			printf("\nPilha esta Vazia. \n");
			
			else
			{
				mostrarpilha(&minhapilha);
			}

              break;
			case 5:
  			  exit(0);
			default: 
			  printf( "\nOpcao invalida ... \n" );
		}
   	    system("pause"); 
	}
}
