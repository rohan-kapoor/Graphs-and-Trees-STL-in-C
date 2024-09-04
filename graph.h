#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Structure for graph
typedef struct Graph{
    int numVertices;
    char** vertexNames;  // To store vertex names
    bool** adjMatrix;  // Adjacency Matrix
} Graph;

// Common graph functions
Graph* create_graph(int numVertices);
void free_graph(Graph* graph);
int get_vertex_index(Graph* graph, char* name);
int add_vertex(Graph *graph, char *name);
void print_graph(Graph* graph);


// Directed graph functions
void add_directed_edge(Graph* graph, char* src, char* dest);
void remove_directed_edge(Graph* graph, char* src, char* dest);
bool is_connected_directed(Graph* graph, char* src, char* dest);

// Undirected graph functions
void add_undirected_edge(Graph* graph, char* src, char* dest);
void remove_undirected_edge(Graph* graph, char* src, char* dest);
bool is_connected_undirected(Graph* graph, char* src, char* dest);