#include <stdio.h>
#include <assert.h>
#include "tree.h"

// Function to perform in-order traversal and collect elements into an array
void collect_in_order(TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    collect_in_order(root->left, arr, index);
    arr[(*index)++] = root->data;
    collect_in_order(root->right, arr, index);
}

// Function to test BST insertion
void test_insert_BST() {
    TreeNode* root = NULL;

    root = insert_BST(root, 50);
    root = insert_BST(root, 30);
    root = insert_BST(root, 20);
    root = insert_BST(root, 40);
    root = insert_BST(root, 70);
    root = insert_BST(root, 60);
    root = insert_BST(root, 80);

    // Collecting in-order traversal into an array
    int arr[7];
    int index = 0;
    collect_in_order(root, arr, &index);

    // To check if the elements are in sorted order
    assert(index == 7);
    assert(arr[0] == 20);
    assert(arr[1] == 30);
    assert(arr[2] == 40);
    assert(arr[3] == 50);
    assert(arr[4] == 60);
    assert(arr[5] == 70);
    assert(arr[6] == 80);

    printf("Insertion test passed!\n");
}

// Function to test BST search
void test_search_BST() {
    TreeNode* root = NULL;

    root = insert_BST(root, 50);
    root = insert_BST(root, 30);
    root = insert_BST(root, 20);
    root = insert_BST(root, 40);
    root = insert_BST(root, 70);
    root = insert_BST(root, 60);
    root = insert_BST(root, 80);

    // Positive search cases
    assert(search_BST(root, 50) != NULL);
    assert(search_BST(root, 30) != NULL);
    assert(search_BST(root, 20) != NULL);
    assert(search_BST(root, 40) != NULL);
    assert(search_BST(root, 70) != NULL);
    assert(search_BST(root, 60) != NULL);
    assert(search_BST(root, 80) != NULL);
    
    // Negative search case
    assert(search_BST(root, 100) == NULL);
    
    printf("Search test passed!\n");
}

// Function to test finding the minimum value in a BST
void test_minimum_value_BST() {
    TreeNode* root = NULL;
    
    root = insert_BST(root, 50);
    root = insert_BST(root, 30);
    root = insert_BST(root, 20);
    root = insert_BST(root, 40);
    root = insert_BST(root, 70);
    root = insert_BST(root, 60);
    root = insert_BST(root, 80);
    
    assert(minimum_value_BST(root) == 20);

    printf("Minimum value test passed!\n");
}

// Function to test node deletion in BST
void test_delete_BST() {
    TreeNode* root = NULL;
    
    root = insert_BST(root, 50);
    root = insert_BST(root, 30);
    root = insert_BST(root, 20);
    root = insert_BST(root, 40);
    root = insert_BST(root, 70);
    root = insert_BST(root, 60);
    root = insert_BST(root, 80);
    
    // Delete node with no children
    root = delete_node_BST(root, 20);
    assert(search_BST(root, 20) == NULL);

    // Delete node with one child
    root = delete_node_BST(root, 30);
    assert(search_BST(root, 30) == NULL);

    // Delete node with two children
    root = delete_node_BST(root, 50);
    assert(search_BST(root, 50) == NULL);

    // Check the remaining nodes
    assert(search_BST(root, 40) != NULL);
    assert(search_BST(root, 70) != NULL);
    assert(search_BST(root, 60) != NULL);
    assert(search_BST(root, 80) != NULL);

    printf("Deletion test passed!\n");
}

// Main function to run all tests
int main() {
    test_insert_BST();
    test_search_BST();
    test_minimum_value_BST();
    test_delete_BST();
    
    printf("All tests passed successfully!\n\n");
    
    return 0;
}
