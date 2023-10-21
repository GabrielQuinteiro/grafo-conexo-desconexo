#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

/* Estrutura para representar um nó da lista de adjacência */
struct Node {
    int data;
    struct Node* next;
};

/* Estrutura para representar um grafo como uma lista de adjacência */
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
};

struct Node* createNode(int data);
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
bool isConnected(struct Graph* graph, int startVertex);



#endif /*GRAFO_H*/
