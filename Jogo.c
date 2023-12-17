#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
//#include "conio2.h"
//#include "conio.c"
//#include "design.c"

int torre[3][7]={
	{6,5,4,3,2,1,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}
};


void desenhaTorres(){
	int i, j = 0;
	system("cls");
	
	for(i=0;i<3;i++){
		printf("TORRE %i - [", i);
		for (j=0;j<7;j++){		
			if(torre[i][j]!=0)
				printf("%d", torre[i][j]);
			else		
				printf(" ");
		}
		printf("]\n\n");
	}	
}

void moveTorre(int sai, int entra){
	int i, j, z, y, sair = 0;
	
	i = 1;
	while(sair == 0){		
		if (torre[sai][i]==0){
			j = torre[sai][i-1];
			torre[sai][i-1]=0;
			y = i-1;
			sair = 1;	
		} 		
		i = i + 1;
	}

	i = 0; sair = 0;
	while(sair == 0){
		z = torre[entra][i];
		
		if (z == 0 && i==0){
			torre[entra][i] = j;
			sair = 1;	
		} 
		
		if (z == 0 && j < torre[entra][i-1]){
			torre[entra][i] = j;
			sair = 1;	
		} 		
		i = i + 1;
		if (i==7){
			printf("Impossivel mover?"); 
			system("pause");
			//mensageBox("Impossivel mover");
			torre[sai][y]=j;
		}
	}
	desenhaTorres();
}

int main (){
	int i, sair = 0, sai, entra, continuar;
	desenhaTorres();
	
		
	while(sair == 0){
		printf("Qual torre vai sair?"); scanf("%d", &sai);		
		printf("Qual torre vai entrar?"); scanf("%d", &entra);
		desenhaTorres();
		//sai = inputBox("Qual torre vai sair ?"," "," ");
		//entra = inputBox("Qual torre vai entrar ?"," "," ");
		moveTorre(sai,entra);
		//continuar = inputBox("Deseja mover outra?","[0]-sim","[1]-Nao");
		printf("Deseja continuar [0]-SIM [1]-NAO ?"); scanf("%d", &continuar);
		desenhaTorres();
		if (continuar ==1) sair = 1;
	}
		
		system("pause");	
	

	return 0;
}




//typedef struct pilha{
//	int valor;
//	struct PILHA *prox;
//}PILHA;
///* Jogo Torre de Hanoi */
//
//void PUSH(int torreOrigem, int *torreDestino);
//void POP();
//void criaTorre(PILHA *Torre);
//int i = 0;
//
//int main() {
//	PILHA torre[2], tmp;
//
//	int topo;
//	
//	tmp.prox = NULL;
//	torre[1].prox = NULL;
//	torre[2].prox = NULL;
//
//	criaTorre(&torre[0]);
//	tmp.prox = malloc(sizeof(PILHA));;
//	torre[0]= tmp;
//	
//	printf("%d\n", torre[0].valor);
//	for(i=0; i>7; i++){
//		
//	}
//	
//	system("pause");
//	return 0;
//}
//
//void criaTorre(PILHA *torre){
//	PILHA tmp;
//	int topo;
//	for(i=0;i>7; i++){
//		if (torre->prox == NULL){
//						
//			topo = malloc(sizeof(PILHA));
//		}
//		torre->valor = i;
//		torre->prox = topo;
//		
//	}
//}
