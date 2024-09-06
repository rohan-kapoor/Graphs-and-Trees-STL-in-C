#!/bin/bash

# Exit if any command fails
set -e

# Directories where test, include, and source files are located
TEST_DIR="./testing"
INCLUDE_DIR="./include"
SRC_DIR="./src"

# A function to map test files to their respective source files
get_source_files() {
    case "$1" in
        test_binary_tree) echo "$SRC_DIR/binary_tree.c $SRC_DIR/common_tree_operations.c" ;;
        test_binary_search_tree) echo "$SRC_DIR/binary_search_tree.c $SRC_DIR/common_tree_operations.c" ;;
        test_common_graph_operations) echo "$SRC_DIR/common_graph_operations.c $SRC_DIR/directed_graph.c $SRC_DIR/queue.c" ;;
        test_common_tree_operations) echo "$SRC_DIR/common_tree_operations.c" ;;
        test_directed_graph) echo "$SRC_DIR/directed_graph.c $SRC_DIR/common_graph_operations.c $SRC_DIR/queue.c" ;;
        test_queue) echo "$SRC_DIR/queue.c" ;;
        test_undirected_graph) echo "$SRC_DIR/undirected_graph.c $SRC_DIR/common_graph_operations.c $SRC_DIR/queue.c" ;;
        *) echo "" ;; # In case a test file doesn't match, no source is added
    esac
}

# Compile and run each test file
for TEST_FILE in "$TEST_DIR"/*.c; do
    # Extract the test name (without .c extension)
    EXEC_NAME=$(basename "$TEST_FILE" .c)
    
    # Get the corresponding source file(s) for the test
    SRC_FILES=$(get_source_files "$EXEC_NAME")
    
    if [ -z "$SRC_FILES" ]; then
        echo "No matching source files for $EXEC_NAME. Skipping..."
        continue
    fi
    
    # Compile the test file, linking it with the appropriate source files
    gcc -o "$EXEC_NAME" "$TEST_FILE" $SRC_FILES -I"$INCLUDE_DIR"
    
    # Run the compiled test
    echo "Running $EXEC_NAME..."
    ./"$EXEC_NAME"

    rm $EXEC_NAME
done

echo "All tests completed successfully."
