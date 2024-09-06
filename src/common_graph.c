#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "queue.h"

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

int* shortest_path(Graph* graph, char* srcName, char* destName, int* pathLength) {
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);

    if (src == -1 || dest == -1) {
        *pathLength = -1;
        return NULL;  // Invalid source or destination name
    }

    bool* visited = (bool*)calloc(graph->numVertices, sizeof(bool));
    int* parent = (int*)calloc(graph->numVertices, sizeof(int));
    int* distance = (int*)calloc(graph->numVertices, sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        distance[i] = INT_MAX;  // Initialize distances to infinity
        parent[i] = -1;         // Initialize parents to -1 (no parent)
    }

    // Create the queue for BFS
    Queue* queue = create_queue(graph->numVertices);
    enqueue(queue, src);
    visited[src] = true;
    distance[src] = 0;

    // Perform BFS
    while (!is_queue_empty(queue)) {
        int vertex = dequeue(queue);

        // Explore all neighbors of the current vertex
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[vertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(queue, i);
                parent[i] = vertex;
                distance[i] = distance[vertex] + 1;

                // If destination is found, exit early
                if (i == dest) {
                    break;
                }
            }
        }
    }

    // If destination is not reachable
    if (distance[dest] == INT_MAX) {
        *pathLength = -1;
        free(visited);
        free(parent);
        free(distance);
        free_queue(queue);
        return NULL;
    }

    // Reconstruct the path from destination to source
    int* path = (int*)malloc(distance[dest] * sizeof(int));
    int current = dest;
    *pathLength = distance[dest];

    for (int i = *pathLength - 1; i >= 0; i--) {
        path[i] = current;
        current = parent[current];
    }

    free(visited);
    free(parent);
    free(distance);
    free_queue(queue);
    return path;
}