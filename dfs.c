#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GREY 1
#define BLACK 2

void addNode(int stack[], int node, int size)
{
    for(int i=0; i < size; i++)
    {
        if (stack[i]==-1)
        {
         stack[i] = node;
            break;
        }
    }
}

void removeNode(int stack[], int size)
{
    for(int i=1; i<size; i++)
    {
        if (stack[i] == -1 || i == size-1)
        {   
         stack[i-1] = -1;
            break;
        }
    }
}

void dfs(int mat[], int color[], int path[], int depth[], int stack[], int size,int node)
{
    int index;
    printf("Exploring node %d\nstack:\n", node);

    for(int i=0; i<size; i++)
    {
        if (stack[i]==-1)
        {   
            index = i-1;
            printf("\n");
            break;
        }
        printf("%d |", stack[i]);
    }

    printf("Current state: \nnode\t| color\t| path\t| depth\n");
    for(int i=0; i<size; i++)
    {
        switch (color[i])
        {
            case WHITE:
                printf("%d\t| white\t| %d\t| %d\n", i, path[i], depth[i]);
                break;
            case GREY:
                printf("%d\t| grey\t| %d\t| %d\n", i, path[i], depth[i]);
                break;
            case BLACK:
                printf("%d\t| black\t| %d\t| %d\n", i, path[i], depth[i]);
                break;
        }
    }

    for(int i=0; i<size; i++)
    {
        if(mat[size*node+i] > 0 && color[i] == WHITE)
        {
            color[i] = GREY;
            path[i] = node;
            depth[i] = depth[node]+1;
            addNode(stack, i, size);
            dfs(mat, color, path, depth, stack, size, i);
            
            printf("Exploring node %d\nstack:\n", node);

            for(int i=0; i<size; i++)
            {
                if (stack[i]==-1)
                {   
                    index = i-1;
                    printf("\n");
                    break;
                }
                printf("%d |", stack[i]);
            }

            printf("Current state: \nnode\t| color\t| path\t| depth\n");
            for(int i=0; i<size; i++)
            {
                switch (color[i])
                {
                    case WHITE:
                        printf("%d\t| white\t| %d\t| %d\n", i, path[i], depth[i]);
                        break;
                    case GREY:
                        printf("%d\t| grey\t| %d\t| %d\n", i, path[i], depth[i]);
                        break;
                    case BLACK:
                        printf("%d\t| black\t| %d\t| %d\n", i, path[i], depth[i]);
                        break;
                }
            }
            color[node] = BLACK;
            removeNode(stack, size);

        }
    }


}

int main()
{
    int size;

    printf("insert the size of adjacency matrix:");
    scanf("%d", &size);

    int mat[size][size], color[size], path[size], depth[size], stack[size];

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
        depth[i] = 0;
        path[i] = -1;
        stack[i] = -1;
        for (int j = 0; j < size; j++)
        {
            printf("%d \t|", mat[i][j]);
        }
        printf("\n");
    }
    color[0] = GREY;
    stack[0]=0;
    dfs(mat[0], color, path, depth, stack, size, 0);
    printf("stack:\n empty\n");


    printf("Current state: \nnode\t| color\t| path\t| depth\n");
    for(int i=0; i<size; i++)
    {
        switch (color[i])
        {
            case WHITE:
                printf("%d\t| white\t| %d\t| %d\n", i, path[i], depth[i]);
                break;
            case GREY:
                printf("%d\t| grey\t| %d\t| %d\n", i, path[i], depth[i]);
                break;
            case BLACK:
                printf("%d\t| black\t| %d\t| %d\n", i, path[i], depth[i]);
                break;
        }
    }
    return 0;
}