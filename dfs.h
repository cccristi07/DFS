#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED
#include "graph.h"
#include "stack.h"
#include <stdbool.h>


void visitNode(GRAPH *g,int node)
{


    g->node_color[node]=GREY;
    printf("%d ",node);

    return ;
}

void DFS(GRAPH *g,STACK *s,int start)
{


    int i,top_node,n;
    bool exist=false;

    visitNode(g,start);
    Push(s,start);


    while(!isEmpty(s))
    {

        exist=false;
        top_node=Top(s);

        for(i=1; i<=g->V ; i++){

            if(g->g_matrix[top_node][i] != 0 && g->node_color[i] == WHITE){ // if node i is adjacent with  top_node and is not visited then

                exist=true;// there is a neighbor of top_node
                n=i;
                g->node_parent[n]=top_node;// parent of n is top_node
                visitNode(g,n);// visit node n
                Push(s,n);// put it in the stack
                break;
            }
        }
        if(exist == false){

            g->node_color[top_node]=BLACK;//finished visiting top_node's neighbors
            Pop(s);
        }
    }

    return;
}

#endif // DFS_H_INCLUDED
