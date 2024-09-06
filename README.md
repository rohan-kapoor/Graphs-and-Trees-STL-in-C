# Graphs and Trees STL in C

This project is an implementation of a Standard Template Library (STL) for graphs and trees in C. The library provides various functionalities for handling directed and undirected graphs, as well as binary trees and binary search trees (BSTs). The code is organized into separate modules for clarity and ease of testing.

## Project Structure

├── include │ ├── graph.h │ ├── queue.h │ └── tree.h ├── src │ ├── binary_tree.c │ ├── binary_search_tree.c │ ├── common_graph_operations.c │ ├── common_tree_operations.c │ ├── directed_graph.c │ ├── queue.c │ └── undirected_graph.c └── testing ├── test_binary_tree.c ├── test_binary_search_tree.c ├── test_common_graph_operations.c ├── test_common_tree_operations.c ├── test_directed_graph.c ├── test_queue.c └── test_undirected_graph.c

Graph and Trees STL in C/
├── include/
│   ├── graph.h
│   ├── queue.h
│   ├── tree.h
├── src/
│   ├── binary_tree.c
│   ├── binary_search_tree.c
│   ├── common_graph_operations.c
│   ├── directed_graph.c
│   ├── queue.c
│   ├── undirected_graph.c
│   └── common_tree_operations.c
│   
├── testing/
│   ├── test_binary_tree.c
│   ├── test_binary_search_tree.c
|   ├── test_common_graph_operations.c
│   ├── test_common_tree_operations.c
|   ├── test_directed_graph.c
│   ├── test_queue.c
│   └── test_undirected_graph.c
├── run_tests.sh
├── .gitignore
└── README.md

### Include Directory
- **graph.h**: Header file for graph-related structures and functions.
- **tree.h**: Header file for tree-related structures and functions.
- **queue.h**: Header file for queue structures used in various algorithms.

### Src Directory
- **binary_tree.c**: Implements binary tree operations such as insertion, deletion, and traversal.
- **binary_search_tree.c**: Implements binary search tree operations including search, insertion, and deletion.
- **common_graph_operations.c**: Contains common operations for graphs like creating and freeing graphs.
- **common_tree_operations.c**: Contains common operations for trees like node creation and traversal.
- **directed_graph.c**: Implements operations specific to directed graphs, such as adding/removing edges and cycle detection.
- **queue.c**: Implements a dynamic queue used in various algorithms.
- **undirected_graph.c**: Implements operations specific to undirected graphs, including adding/removing edges and cycle detection.

### Testing Directory
- **test_binary_tree.c**: Unit tests for binary tree operations.
- **test_binary_search_tree.c**: Unit tests for binary search tree operations.
- **test_common_graph_operations.c**: Unit tests for common graph operations.
- **test_common_tree_operations.c**: Unit tests for common tree operations.
- **test_directed_graph.c**: Unit tests for directed graph operations.
- **test_queue.c**: Unit tests for the queue implementation.
- **test_undirected_graph.c**: Unit tests for undirected graph operations.

## Features

### Graph Operations
- **Directed Graph**: Add/Remove edges, check connectivity, detect cycles.
- **Undirected Graph**: Add/Remove edges, check connectivity, detect cycles.
- **Shortest Path**: Find the shortest path in a graph using BFS.

### Tree Operations
- **Binary Tree**: Level order insertion and deletion, traversals (pre-order, in-order, post-order).
- **Binary Search Tree (BST)**: Search, insertion, deletion, and finding the minimum value.
- **Common Tree Functions**: Tree height calculation, level order traversal, and tree memory management.

## Getting Started

### Prerequisites
- GCC (GNU Compiler Collection) - Ensure you have the GCC Compile installed on your system

### Building the Project
You can compile individual components or the entire project using a run_all.sh or directly using GCC.

#### Compile Individual Components
Compile specific components using GCC:

```bash
gcc -o binary_tree src/binary_tree.c include/tree.h
```

### Running Tests
To run all the tests, you can use the provided `run_tests.sh` script. This script compiles and executes all the test files located in the `testing` directory.

To run the tests, use the following command:

```bash
./run_tests.sh
```

### Running the Entire Code
To run the entire project, you can use the `run_all.sh` script. This script is designed to compile all source files and execute the main functionalities of the project in one go.

To run the script, execute the following command in your terminal:

```bash
./run_all.sh
```
