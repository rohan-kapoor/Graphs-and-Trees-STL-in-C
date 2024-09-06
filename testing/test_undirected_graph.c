#include <assert.h>
#include "graph.h"

// Function to test undirected edge operations
void test_undirected_edge_operations() {
    Graph* graph = create_graph(5);

    add_undirected_edge(graph, "A", "B");
    add_undirected_edge(graph, "B", "C");
    add_undirected_edge(graph, "C", "D");

    assert(is_connected_undirected(graph, "A", "B") == true);
    assert(is_connected_undirected(graph, "B", "C") == true);
    assert(is_connected_undirected(graph, "C", "D") == true);
    assert(is_connected_undirected(graph, "A", "C") == false);

    remove_undirected_edge(graph, "B", "C");
    assert(is_connected_undirected(graph, "B", "C") == false);

    printf("Undirected edge operations tests passed!\n");

    // Free memory
    free_graph(graph);
}

// Function to test undirected cycle detection
void test_undirected_cycle_detection() {
    Graph* graph = create_graph(5);

    add_undirected_edge(graph, "A", "B");
    add_undirected_edge(graph, "B", "C");
    add_undirected_edge(graph, "C", "A"); // Creating a cycle

    assert(is_cyclic_undirected(graph) == true);

    remove_undirected_edge(graph, "C", "A"); // Removing edge to break the cycle

    assert(is_cyclic_undirected(graph) == false);

    printf("Undirected cycle detection tests passed!\n");

    // Free memory
    free_graph(graph);
}

// Main function to run all tests
int main() {
    test_undirected_edge_operations();
    test_undirected_cycle_detection();

    printf("All undirected graph tests passed successfully!\n\n");

    return 0;
}
