#include <stdio.h>
#include <stdlib.h>

int guloso(int matAdja[],int * vet, int origem, int destino, int n,int passos){
	int j, i, aux, count;
	aux=0; 
	count=0;
	

	for(j=0;j<n;j++){
		if (matAdja[origem*n+j]!=0){
			printf("no id %d o caminho %d custa %d\n",origem, j, matAdja[origem*n+j]);
			if(j == destino){
				printf("o caminho escolhido foi %d\n",j);
				printf("Cheguei!\n");
				return 0;
			}
			if(origem!=j){
				if (matAdja[origem*n+aux]==0 && matAdja[origem*n+j]!=0){
					aux=j;
					count++;
				}
				if (matAdja[origem*n+j] < matAdja[origem*n+aux]){
					aux = j;
					count++;
				}
			}
		}
	}


	if (count!=0){
		for(i=0; i<n; i++){
			if(vet[i]==aux){
				
				printf("Cansei, impossível fazer com Guloso\n");
				return 0;
			
			}
		}
		printf("o caminho escolhido foi %d\n",aux);
		vet[passos]=aux;
		passos++;

		if (aux==destino){
			printf("Cheguei!");
			return 0;
		}
		else{
			count=0;
		}
		
	}
	else{
		printf("Impossível com guloso.\n");
		return 0;
	}
	
	if (count == 0){
		guloso(matAdja, vet, aux, destino, n, passos);
	}
	return 0;
}



int main(){
	
	int n, i, origem, destino;
	
	printf("tamanho da matriz \n");
	scanf("%d", &n);

	int matAdja[n][n];

	for (i=0; i<n;i++){
		for(int j=0; j<n; j++){
			printf("Lendo valor da posição %d,%d: \n", i,j);
			scanf("%d", &matAdja[i][j]);
		}

	}
	printf("\n****** Matrix *****\n");

	for (int i=0; i<n;i++){
		for(int j=0; j<n; j++){
			printf("%d \t|", matAdja[i][j]);
		}
		printf("\n");
	}
	int vet[n];
	for (i=0; i<n ;i++){
		vet[i]=-1;
	}

	printf("Digite o id de Origem (linha equivalente da matriz[0 até tamanho-1])\n");
	scanf("%d", &origem);
	printf("Digite o id de Destino (linha equivalente da matriz[0 até tamanho-1]) \n");
	scanf("%d", &destino);

	guloso(matAdja[0], vet, origem, destino, n, 0);
	
	return 0;
}