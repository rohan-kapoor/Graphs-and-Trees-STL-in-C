#include "graph.h"

void add_undirected_edge(Graph* graph, char* srcName, char* destName){
    int src = add_vertex(graph, srcName);
    int dest = add_vertex(graph, destName);
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true;
}

void remove_undirected_edge(Graph* graph, char* srcName, char* destName){
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if(src != -1 && dest != -1){
        graph->adjMatrix[src][dest] = false;
        graph->adjMatrix[dest][src] = false;
    }
}

bool is_connected_undirected(Graph* graph, char* srcName, char* destName){
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if(src != -1 && dest != -1){
        return graph->adjMatrix[src][dest];
    }
    return false;
}

bool dfs_cycle_undirected(Graph* graph, int vertex, bool* visited, int parent) {
    visited[vertex] = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i]) {
            if (!visited[i]) {
                if (dfs_cycle_undirected(graph, i, visited, vertex)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }

    return false;
}

bool is_cyclic_undirected(Graph* graph) {
    bool* visited = (bool*)calloc(graph->numVertices, sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfs_cycle_undirected(graph, i, visited, -1)) {
                free(visited);
                return true;
            }
        }
    }

    free(visited);
    return false;
}