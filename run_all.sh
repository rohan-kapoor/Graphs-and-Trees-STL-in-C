#!/bin/bash

# Set the executable name
EXEC_NAME="main_program"

# Compile all source files including the main file
gcc -o $EXEC_NAME src/binary_tree.c src/binary_search_tree.c src/common_graph_operations.c src/common_tree_operations.c src/directed_graph.c src/undirected_graph.c src/queue.c main.c -Iinclude

# Run the executable
echo "Running the entire project..."
./$EXEC_NAME

# Clean up the executable
rm $EXEC_NAME
