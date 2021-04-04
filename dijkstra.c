#include <stdio.h>
#include <stdlib.h>

int menorNaoVisitado(int dist[], int vis[], int n, int max)
{
int menor=max;
int indice, count=-1;

for(int i=0; i<n; i++)
{
    if (vis[i]==0 && dist[i]<menor){
        indice=i;
        menor=dist[i];
        count ++;
    }
}
if (count < 0)
{
    return -1;
}
return indice;
}



int dijkstra(int matAdja[], int vis[], int dist[], int anterior[], int n, int ini,int max)
{   printf("\nVisitando %d\n",ini);
    vis[ini]=1;
    if(dist[ini]==max)
    {  
        dist[ini]=0;
    }
    for(int i=0; i<n; i++)
    {  
         if(matAdja[ini*n+i]>0 && vis[i]==0 && dist[i] > dist[ini]+matAdja[ini*n+i])
        {
            
            dist[i] = dist[ini]+matAdja[ini*n+i];
            anterior[i]=ini;
       
        }
    }
    printf("\tEstado atual\n");
    printf("vert.\t| Vis\t| valor\t| anterior\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t| %d\t| %d\t| %d\n",i,vis[i],dist[i],anterior[i]);
    }
    ini = menorNaoVisitado(dist,vis,n, max);
    if(ini<0)
    {
        printf("Terminou\n");
        return -1;
    }
    dijkstra(matAdja, vis, dist, anterior, n, ini, max);
}

int main()
{
    int n, max;
    

	printf("tamanho da matriz \n");
	scanf("%d", &n);

	int matAdja[n][n];
    int vis[n], dist[n], anterior[n];
    
	for (int i=0; i<n;i++)
    {
		for(int j=0; j<n; j++)
        {
			printf("Lendo valor da posição %d,%d: \n", i,j);
			scanf("%d", &matAdja[i][j]);
            max+=matAdja[i][j];
		}

	}
	printf("\n****** Matrix *****\n");

	for (int i=0; i<n;i++)
    {   vis[i]=0;
        dist[i]=max;
        anterior[i]=-1;
		for(int j=0; j<n; j++)
        {
			printf("%d \t|", matAdja[i][j]);
		}
		printf("\n");
    }
    dijkstra(matAdja[0], vis, dist,anterior, n, 0, max);
    return 0;
}