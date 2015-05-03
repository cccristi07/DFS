#include <stdio.h>
#include "stack.h"
#include "graph.h"
#include "dfs.h"
int main()
{

    FILE *f=fopen("graph.in","rt");

    if(f == NULL)
        perror("");

    int v1,v2,V;

    fscanf(f,"%d",&V);
    STACK *s=newStack();

    GRAPH *g = newGraph(V);

    while(!feof(f)){

        fscanf(f,"%d %d",&v1,&v2);
        addEdge(g,v1,v2);
    }

    DFS(g,s,1);

    fclose(f);
    freeGraph(g);



    return 0;

}
