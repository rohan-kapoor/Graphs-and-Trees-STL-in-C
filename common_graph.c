#include "graph.h"

Graph *create_graph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->vertexNames = (char **)malloc(numVertices * sizeof(char *));
    for (int i = 0; i < numVertices; i++)
    {
        graph->vertexNames[i] = NULL;
    }

    graph->adjMatrix = (bool **)malloc(numVertices * sizeof(bool *));
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjMatrix[i] = (bool *)calloc(numVertices, sizeof(bool));
    }

    return graph;
}

void free_graph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        free(graph->vertexNames[i]);
        free(graph->adjMatrix[i]);
    }
    free(graph->vertexNames);
    free(graph->adjMatrix);
    free(graph);
}

int get_vertex_index(Graph *graph, char *name)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->vertexNames[i] && strcmp(graph->vertexNames[i], name) == 0)
        {
            return i;
        }
    }

    return -1;
}

int add_vertex(Graph *graph, char *name)
{
    int index = get_vertex_index(graph, name);
    if (index != -1)
    {
        return index;
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->vertexNames[i] == NULL)
        {
            graph->vertexNames[i] = strdup(name);
            return i;
        }
    }

    // Expanding the graph in case no empty spot
    int newVertexIndex = graph->numVertices;
    graph->numVertices++;

    graph->vertexNames = (char **)realloc(graph->vertexNames, graph->numVertices * sizeof(char *));
    graph->adjMatrix = (bool **)realloc(graph->adjMatrix, graph->numVertices * sizeof(bool *));
    for (int i = 0; i < graph->numVertices - 1; i++)
    {
        graph->adjMatrix[i] = (bool *)realloc(graph->adjMatrix[i], graph->numVertices * sizeof(bool));
        graph->adjMatrix[i][newVertexIndex] = false;
    }

    graph->adjMatrix[newVertexIndex] = (bool *)calloc(graph->numVertices, sizeof(bool));
    graph->vertexNames[newVertexIndex] = strdup(name);

    return newVertexIndex;
}

void remove_vertex(Graph *graph, int index)
{
    if (graph->vertexNames[index])
    {
        free(graph->vertexNames[index]);
        graph->vertexNames[index] = NULL;

        // Removing edges related to this vertex
        for (int i = 0; i < graph->numVertices; i++)
        {
            graph->adjMatrix[index][i] = false;
            graph->adjMatrix[i][index] = false;
        }
    }
}

void print_graph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->vertexNames[i])
        {
            printf("%s: ", graph->vertexNames[i]);
            for (int j = 0; j < graph->numVertices; j++)
            {
                if (graph->adjMatrix[i][j])
                {
                    printf("%s  ", graph->vertexNames[j]);
                }
            }
            printf("\n");
        }
    }
}