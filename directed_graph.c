#include "graph.h"

void add_directed_edge(Graph* graph, char* srcName, char* destName){
    int src = add_vertex(graph, srcName);
    int dest = add_vertex(graph, destName);
    graph->adjMatrix[src][dest] = true;
}

void remove_directed_edge(Graph* graph, char* srcName, char* destName){
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if(src != -1 && dest != -1){
        graph->adjMatrix[src][dest] = false;
    }
}

bool is_connected_directed(Graph* graph, char* srcName, char* destName){
    int src = get_vertex_index(graph, srcName);
    int dest = get_vertex_index(graph, destName);
    if(src != -1 && dest != -1){
        return graph->adjMatrix[src][dest];
    }
    return false;
}