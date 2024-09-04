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