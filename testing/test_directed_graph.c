#include <assert.h>
#include "graph.h"

// Function to test edge operations
void test_edge_operations()
{
    Graph *graph = create_graph(5);

    add_directed_edge(graph, "A", "B");
    add_directed_edge(graph, "B", "C");
    add_directed_edge(graph, "C", "D");

    assert(is_connected_directed(graph, "A", "B") == true);
    assert(is_connected_directed(graph, "B", "C") == true);
    assert(is_connected_directed(graph, "C", "D") == true);
    assert(is_connected_directed(graph, "A", "C") == false);

    remove_directed_edge(graph, "B", "C");
    assert(is_connected_directed(graph, "B", "C") == false);

    printf("Edge operations tests passed!\n");

    // Free memory
    free_graph(graph);
}

// Function to test cycle detection
void test_cycle_detection()
{
    Graph *graph = create_graph(5);

    add_directed_edge(graph, "A", "B");
    add_directed_edge(graph, "B", "C");
    add_directed_edge(graph, "C", "A"); // Creating a cycle

    assert(is_cyclic_directed(graph) == true);

    remove_directed_edge(graph, "C", "A"); // Removing edge to break the cycle

    assert(is_cyclic_directed(graph) == false);

    printf("Cycle detection tests passed!\n");

    // Free memory
    free_graph(graph);
}

// Main function to run all tests
int main()
{
    test_edge_operations();
    test_cycle_detection();

    printf("All directed graph tests passed successfully!\n\n");

    return 0;
}
