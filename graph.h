#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define WHITE 0 // node is undiscovered
#define GREY 1  // node is in process
#define BLACK 2 // node is discovered

#include <stdlib.h>


typedef struct graph{

    int V; // Number of vertices
    int **g_matrix; // Adjacency matrix for graph
    int *node_color; // Tells is node is visited or not
    int *node_parent; // Vector of parents for nodes

}GRAPH;


GRAPH *newGraph(int V){

    int i;
    GRAPH *g=malloc(sizeof(GRAPH));

    g->V=V;

    //allocation of the adjacency matrix with 0

    g->g_matrix=(int **)calloc(V+1,sizeof(int*)); // to start counting from 1 and not from 0

    for(i=0 ; i<=V ; i++){

        g->g_matrix[i]=(int*)calloc(V+1,sizeof(int));
    }


    // allocation and initialization of the vectors of colors, parents and begin and fin times,
    g->node_color=calloc(V+1,sizeof(int));
    g->node_parent=calloc(V+1,sizeof(int));

    return g;

}

// Adds an edge between two vertices,in the initialized matrix

void addEdge(GRAPH *g,int v1,int v2){


    if(v1 > g->V +1 || v1 > g->V + 1){

        printf("Vertices index exceeds adjacency matrix index");
        return;
    }
    g->g_matrix[v1][v2]=1;
    g->g_matrix[v2][v1]=1;
}


void printGraph(GRAPH *g){

    int i,j;

    for(i=1; i< g->V +1 ; i++){

        for(j=1; j< g->V +1; j++)
            printf("%d ",g->g_matrix[i][j]);

        printf("\n");
    }
    return ;
}

void freeGraph(GRAPH *g){

    free(g->node_color);
    free(g->node_parent);

    int i;

    for(i=0; i<g->V +1 ; i++)
        free(g->g_matrix[i]);

    free(g->g_matrix);

    free(g);

}
#endif // GRAPH_H_INCLUDED
