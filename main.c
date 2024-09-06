#include <stdio.h>
#include "graph.h"
#include "tree.h"

// Sample function to demonstrate directed graph operations
void demo_directed_graph_operations() {
    printf("Directed Graph Operations: \n");

    Graph* graph = create_graph(5);

    add_directed_edge(graph, "A", "B");
    add_directed_edge(graph, "B", "C");
    add_directed_edge(graph, "C", "D");
    add_directed_edge(graph, "D", "E");
    add_directed_edge(graph, "E", "A");
    add_directed_edge(graph, "A", "C");

    print_graph(graph);

    // Check for cycles in the directed graph
    if (is_cyclic_directed(graph)) {
        printf("\nThe directed graph contains a cycle.\n");
    } else {
        printf("\nThe directed graph does not contain a cycle.\n");
    }

    // Find shortest path from A to D
    int pathLength;
    char** path = shortest_path(graph, "A", "D", &pathLength);
    if (path) {
        printf("\nShortest path from A to D:\n");
        for (int i = 0; i < pathLength; i++) {
            printf("%s ", path[i]);
        }
        printf("\n");
        free(path);
    } else {
        printf("\nNo path found from A to D.\n");
    }

    free_graph(graph);
}

// Sample function to demonstrate BST operations
void demo_bst_operations() {
    printf("Binary Search Tree Operations: \n");

    // Create a binary search tree
    TreeNode* root = NULL;
    root = insert_BST(root, 10);
    root = insert_BST(root, 5);
    root = insert_BST(root, 15);
    root = insert_BST(root, 3);
    root = insert_BST(root, 7);

    // Print BST traversals
    printf("\nIn-order traversal:\n");
    in_order_traversal(root); // sorted order
    printf("\n");

    printf("\nDeleting 7 from BST\n");

    printf("\nIn-order traversal:\n");
    delete_node_BST(root, 7);
    in_order_traversal(root);
    printf("\n");

    // Free tree
    free_tree(root);
}

int main() {
    demo_directed_graph_operations();
    demo_bst_operations();

    return 0;
}
