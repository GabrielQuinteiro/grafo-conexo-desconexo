#include "grafo.h"

/* funcao para criar um novo no */
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* funcao para criar um grafo com 'numVertices' vertices */
struct Graph* createGraph(int numVertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

/* funcao para adicionar uma aresta ao grafo */
void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    /* uma aresta nao direcionada deve ser adicionada nos dois sentidos */
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

/* funcao para realizar a busca em largura (BFS) e verificar a conexidade */
bool isConnected(struct Graph* graph, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}
