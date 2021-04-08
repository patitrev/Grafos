#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GREY 1
#define BLACK 2

void addNode(int row[], int node, int size)
{
    for(int i=0; i < size; i++)
    {
        if (row[i]==-1)
        {
            row[i] = node;
            break;
        }
    }
}

void removeNode(int row[], int size)
{
    for(int i=1; i<size; i++)
    {
        row[i-1] = row[i];
        if(row[i] == -1)
        {
            break;
        }
    }
}

void bfs(int mat[], int color[], int path[], int skips[], int row[], int size)
{

    printf("Exploring node %d\nrow:\n", row[0]);

    for(int i=0; i<size; i++)
    {
        if (row[i]==-1)
        {
            printf("\n");
            break;
        }
        printf("%d |", row[i]);
    }

    printf("Current state: \nnode\t| color\t| path\t| skips\n");
    for(int i=0; i<size; i++)
    {
        switch (color[i])
        {
            case WHITE:
                printf("%d\t| white\t| %d\t| %d\n", i, path[i], skips[i]);
                break;
            case GREY:
                printf("%d\t| grey\t| %d\t| %d\n", i, path[i], skips[i]);
                break;
            case BLACK:
                printf("%d\t| black\t| %d\t| %d\n", i, path[i], skips[i]);
                break;
        }
    }

    for(int i=0; i<size; i++)
    {
        if(mat[size*row[0]+i] > 0 && color[i] == WHITE)
        {
            color[i] = GREY;
            path[i] = row[0];
            skips[i] = skips[row[0]]+1;
            addNode(row, i, size);
        }
    }

    color[row[0]] = BLACK;
    removeNode(row, size);

   
    if(row[0]!=-1)
    {
        bfs(mat, color, path, skips, row, size);
    }
    printf("row:\nempty\n");
    printf("Current state: \nnode\t| color\t| path\t| skips\n");
    for(int i=0; i<size; i++)
    {
        switch (color[i])
        {
            case WHITE:
                printf("%d\t| white\t| %d\t| %d\n", i, path[i], skips[i]);
                break;
            case GREY:
                printf("%d\t| grey\t| %d\t| %d\n", i, path[i], skips[i]);
                break;
            case BLACK:
                printf("%d\t| black\t| %d\t| %d\n", i, path[i], skips[i]);
                break;
        }
    }


}

int main()
{
    int size;

    printf("insert the size of adjacency matrix:");
    scanf("%d", &size);

    int mat[size][size], color[size], path[size], skips[size], row[size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Reading %d,%d position value: \n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n****** Matrix *****\n");

    for (int i = 0; i < size; i++)
    {
        color[i] = WHITE;
        skips[i] = 0;
        path[i] = -1;
        row[i] = -1;
        for (int j = 0; j < size; j++)
        {
            printf("%d \t|", mat[i][j]);
        }
        printf("\n");
    }
    color[0] = GREY;
    row[0]=0;
    bfs(mat[0], color, path, skips, row, size);
    return 0;
}