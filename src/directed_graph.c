#include "graph.h"

// Function to add a directed edge to graph
void add_directed_edge(Graph *graph, char *srcName, char *destName)
{
    int src = add_vertex(graph, srcName);
    int dest = add_vertex(graph, destName);
    graph->adjMatrix[src][dest] = true;
}

// Function to remove a directed edge from graph
void remove_directed_edge(Graph *graph, char *srcName, char *destName)
{
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if (src != -1 && dest != -1)
    {
        graph->adjMatrix[src][dest] = false;
    }
}

// Function to check if the two vertices are connected
bool is_connected_directed(Graph *graph, char *srcName, char *destName)
{
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if (src != -1 && dest != -1)
    {
        return graph->adjMatrix[src][dest];
    }
    return false;
}

// Function to detect a cycle in graph
bool dfs_cycle_directed(Graph *graph, int vertex, bool *visited, bool *recursionStack)
{
    if (!visited[vertex])
    {
        visited[vertex] = true;
        recursionStack[vertex] = true;

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjMatrix[vertex][i])
            {
                if (!visited[i] && dfs_cycle_directed(graph, i, visited, recursionStack))
                {
                    return true;
                }
                else if (recursionStack[i])
                {
                    return true;
                }
            }
        }
    }
    recursionStack[vertex] = false;
    return false;
}

// Function which returns if directed graph is cyclic by calling (dfs_cycle_directed) function
bool is_cyclic_directed(Graph *graph)
{
    bool *visited = (bool *)calloc(graph->numVertices, sizeof(bool));
    bool *recursionStack = (bool *)calloc(graph->numVertices, sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (dfs_cycle_directed(graph, i, visited, recursionStack))
        {
            free(visited);
            free(recursionStack);
            return true;
        }
    }

    free(visited);
    free(recursionStack);
    return false;
}