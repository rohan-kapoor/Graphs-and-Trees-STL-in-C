#include <stdio.h>
// #include "stl.h"
#include "graph.h"

int main() {
    // TreeNode* root = create_node(8);
    // insert_BST(root, 6);
    // insert_BST(root, 7);
    // insert_BST(root, 3);
    // insert_BST(root, 1);
    // insert_BST(root, 5);
    // insert_BST(root, 2);
    // in_order(root);
    // printf("\n");

    // TreeNode* root2 = create_node(1);
    // insert(root2, 3);
    // insert(root2, 5);
    // in_order(root2);

    // Graph* graph = create_graph(0);
    // add_undirected_edge(graph, "delhi", "mumbai");
    // add_undirected_edge(graph, "mumbai", "jalandhar");
    // add_directed_edge(graph, "C", "D");
    // add_directed_edge(graph, "C", "E");

    // print_graph(graph);

    Graph* graph = create_graph(5);

    add_directed_edge(graph, "A", "B");
    add_directed_edge(graph, "B", "C");
    add_directed_edge(graph, "C", "D");
    add_directed_edge(graph, "D", "E");
    add_directed_edge(graph, "A", "D");
    add_directed_edge(graph, "E", "A");

    print_graph(graph);

    if (is_connected_directed(graph, "A", "B")) {
        printf("A is connected to B in a directed graph.\n");
    } else {
        printf("A is not connected to B.\n");
    }

    if (is_connected_directed(graph, "A", "C")) {
        printf("A is connected to C in a directed graph.\n");
    } else {
        printf("A is not connected to C.\n");
    }

    if (is_cyclic_directed(graph)) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("The graph does not contain a cycle.\n");
    }

    int pathLength;
    int* path = shortest_path(graph, "A", "E", &pathLength);
    if (path != NULL) {
        printf("Shortest path from A to E is of length %d:\nA ", pathLength);
        for (int i = 0; i < pathLength; i++) {
            printf("%s ", graph->vertexNames[path[i]]);
        }
        printf("\n");
        free(path);  // Free the path array
    } else {
        printf("No path exists from A to E.\n");
    }

    return 0;
}