#include "graph.h"

// Function to add undirected edge to graph
void add_undirected_edge(Graph *graph, char *srcName, char *destName)
{
    int src = add_vertex(graph, srcName);
    int dest = add_vertex(graph, destName);
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true;
}

// Function to remove undirected edge from graph
void remove_undirected_edge(Graph *graph, char *srcName, char *destName)
{
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if (src != -1 && dest != -1)
    {
        graph->adjMatrix[src][dest] = false;
        graph->adjMatrix[dest][src] = false;
    }
}

// Function to check if the two vertices are connected
bool is_connected_undirected(Graph *graph, char *srcName, char *destName)
{
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if (src != -1 && dest != -1)
    {
        return graph->adjMatrix[src][dest];
    }
    return false;
}

// Function to detect a cycle in undirected graph
bool dfs_cycle_undirected(Graph *graph, int vertex, bool *visited, int parent)
{
    visited[vertex] = true;

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjMatrix[vertex][i])
        {
            if (!visited[i])
            {
                if (dfs_cycle_undirected(graph, i, visited, vertex))
                {
                    return true;
                }
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }

    return false;
}

// Function which returns if undirected graph is cyclic by calling (dfs_cycle_undirected) function
bool is_cyclic_undirected(Graph *graph)
{
    bool *visited = (bool *)calloc(graph->numVertices, sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!visited[i])
        {
            if (dfs_cycle_undirected(graph, i, visited, -1))
            {
                free(visited);
                return true;
            }
        }
    }

    free(visited);
    return false;
}