#ifdef __unix__
#include <stdlib.h>
#include <unistd.h>

#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"

int main()
{
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);
    struct Graph* graph2 = createGraph(numVertices);
    struct Graph* graph3;
    int startVertex;
    int opcao;

    do
    {
        #ifdef OS_Windows
        system("cls");
        #else
        system("clear");
        #endif
        printf("=======================================================\n");
        printf("|                 Escolha uma opcao                   |\n");
        printf("|=====================================================|\n");
        printf("| 1. Exemplo Grafo conexo                             |\n");
        printf("|-----------------------------------------------------|\n");
        printf("| 2. Exemplo Grafo desconexo                          |\n");
        printf("|-----------------------------------------------------|\n");
        printf("| 3. Outro exemplo                                    |\n");
        printf("|-----------------------------------------------------|\n");
        printf("| 0. Sair                                             |\n");
        printf("=======================================================\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
                #ifdef OS_Windows
                system("cls");
                #else
                system("clear");
                #endif

                printf("=======================================================\n");
                printf("|                  Fim do Programa!                   |\n");
                printf("=======================================================\n");

                return 0;
            break;
            case 1:
                addEdge(graph, 0, 1);
                addEdge(graph, 0, 2);
                addEdge(graph, 1, 3);
                addEdge(graph, 3, 4);

                startVertex = 0;
                if (isConnected(graph, startVertex))
                    printf("\n\nO grafo é conexo.\n\n");
                else
                    printf("\n\nO grafo não é conexo.\n\n");
                 #ifdef OS_Windows
                system("pause");
                #else
                system("echo 'Pressione enter para continuar...'; read dummy;");
                #endif
            break;

            case 2:
                addEdge(graph2, 0, 1);
                addEdge(graph2, 2, 3);
                addEdge(graph2, 3, 4);

                startVertex = 0;
                if (isConnected(graph2, startVertex))
                    printf("\n\nO grafo é conexo.\n\n");
                else
                    printf("\n\nO grafo não é conexo.\n\n");

                #ifdef OS_Windows
                system("pause");
                #else
                system("echo 'Pressione enter para continuar...'; read dummy;");
                #endif
            break;

            case 3:
                printf("Informe a quantidade de vertices de seu Grafo (max 100): ")
                scanf("%d", numVertices);
                graph3 = createGraph(numVertices);

                printf("inacabado...")
            break;

            default:
                #ifdef OS_Windows
                system("cls");
                #else
                system("clear");
                #endif

                printf("\nInsira um valor valido!\n");
                #ifdef OS_Windows
                system("pause");
                #else
                system("echo 'Pressione enter para continuar...'; read dummy;");
                #endif
            break;
        }
    } while (opcao != 0);
    return 0;
}
