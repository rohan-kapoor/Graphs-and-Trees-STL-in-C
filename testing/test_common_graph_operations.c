#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "graph.h"
#include "queue.h"

// Function to test graph creation
void test_graph_creation() {
    int numVertices = 5;
    Graph* graph = create_graph(numVertices);

    assert(graph != NULL);
    assert(graph->numVertices == numVertices);

    // Check if vertexNames and adjMatrix are properly allocated
    for (int i = 0; i < numVertices; i++) {
        assert(graph->vertexNames[i] == NULL);
        for (int j = 0; j < numVertices; j++) {
            assert(graph->adjMatrix[i][j] == false);
        }
    }

    free_graph(graph);
    printf("Graph creation test passed!\n");
}

// Function to test vertex addition and removal
void test_vertex_operations() {
    Graph* graph = create_graph(2);

    // Add vertices
    int v1 = add_vertex(graph, "A");
    int v2 = add_vertex(graph, "B");
    int v3 = add_vertex(graph, "C");

    assert(v1 == 0);
    assert(v2 == 1);
    assert(v3 == 2);

    // Test if the graph expands correctly
    assert(graph->numVertices == 3);
    assert(graph->vertexNames[0] != NULL && strcmp(graph->vertexNames[0], "A") == 0);
    assert(graph->vertexNames[1] != NULL && strcmp(graph->vertexNames[1], "B") == 0);
    assert(graph->vertexNames[2] != NULL && strcmp(graph->vertexNames[2], "C") == 0);

    // Remove vertex
    remove_vertex(graph, 1);

    assert(graph->vertexNames[1] == NULL);
    for (int i = 0; i < graph->numVertices; i++) {
        assert(graph->adjMatrix[1][i] == false);
        assert(graph->adjMatrix[i][1] == false);
    }

    free_graph(graph);
    printf("Vertex operations test passed!\n");
}

// Function to test graph printing
void test_print_graph() {
    Graph* graph = create_graph(3);
    add_vertex(graph, "A");
    add_vertex(graph, "B");
    add_vertex(graph, "C");

    graph->adjMatrix[0][1] = true;
    graph->adjMatrix[1][0] = true;  // Undirected edge

    printf("Graph structure:\n");
    print_graph(graph);

    // Manually verify the output
    printf("\nExpected:\nA: B\nB: A\nC:\n");

    free_graph(graph);
    printf("Print graph test passed!\n");
}

// Function to test shortest path
void test_shortest_path() {
    
    int numVertices = 6;
    Graph* graph = create_graph(numVertices);

    // Add vertices (vertex names)
    add_vertex(graph, "A");
    add_vertex(graph, "B");
    add_vertex(graph, "C");
    add_vertex(graph, "D");
    add_vertex(graph, "E");
    add_vertex(graph, "F");

    add_directed_edge(graph, "A", "B");
    add_directed_edge(graph, "A", "C");
    add_directed_edge(graph, "B", "D");
    add_directed_edge(graph, "C", "D");
    add_directed_edge(graph, "C", "E");
    add_directed_edge(graph, "D", "F");
    add_directed_edge(graph, "E", "F");

    // Test the shortest path from A to F
    int pathLength;
    char** path = shortest_path(graph, "A", "F", &pathLength);

    assert(pathLength == 4); // The shortest path A -> C -> D -> F has 4 vertices

    // Check if the vertices in the path match the expected shortest path
    assert(strcmp(path[0], "A") == 0);
    assert(strcmp(path[1], "B") == 0);
    assert(strcmp(path[2], "D") == 0);
    assert(strcmp(path[3], "F") == 0);

    free(path);
    free_graph(graph);

    printf("All tests passed!\n");
}

// Main function to run all tests
int main() {
    test_graph_creation();
    test_vertex_operations();
    test_print_graph();
    test_shortest_path();

    printf("All graph tests passed successfully!\n\n");

    return 0;
}
